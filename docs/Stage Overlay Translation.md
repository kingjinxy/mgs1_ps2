# Stage overlay translation

How a stage overlay that isn't hand-decompiled gets into the port: it's taken apart from the PS1 binary,
translated to C that behaves exactly like the original machine code, and linked in. This applies to overlays the decomp
has split into `INCLUDE_ASM` stubs but not decompiled (`s07b`, `s08b`), and to overlays it hasn't split at all (`s10a`, and
`s11b`, `s11h`, `s15a`, `s17a`, `s18a`, `s19a` on the TAS route). Everything here is port-only (`MGS_PORT`); the matching
build never sees it.

History and dead ends are in `docs/Running Walkthrough.md`, Steps 29–38.

## The tools

| Tool | Input | Output |
|---|---|---|
| `tools/port/stage_split.py OVL` | the stage in the disc's `STAGE.DIR` (`~/emu/mgs-integral/disc1.bin`) | per-function stubs, a symbol map, the overlay's data in C, the stage's chara table |
| `tools/port/mips2c.py OVL BASE` | the stubs and the map | one C file per function (`source/overlays/OVL/recomp/*.inc`) |
| `source/include/recomp.h` | | the runtime the translated C uses: registers, stack frame, calls, unaligned loads/stores, the GTE |
| `build/overlays_ps2.py`, `build/link_ps2.py` | | link the overlay into `mgs.elf`, with its `.data`/`.bss` ranges for the per-load reset (`docs/Overlay Data Reset.md`) |

`BASE` is the overlay's load address, `0x800C3208` for every stage.

## Step 1: split (only for overlays the decomp hasn't split)

```
python3 tools/port/stage_split.py s10a
```

It reads the stage from the disc and writes:

- `build/OVL.matching.bin`: the stage binary as loaded. `mips2c.py` reads jump tables from it.
- `obj_ps2/stage_split/OVL/OVL_<ADDR>.s`: one stub per function, as `dw` words in the decomp's format. They live outside
  `asm/` and have no `INCLUDE_ASM`, so the matching build doesn't pick them up.
- `obj/asm_OVL_lhs.map`: the resident symbols from the matching build's map, plus generated names for the overlay's
  own functions (`s10a_800C5EF4`) and data labels (`s10a_dat_800E4108`).
- `source/overlays/OVL/OVL.c`: all under `#ifdef MGS_PORT`. It holds the `#include`s of the translated functions and the
  overlay's `.data`, `.rodata` and `.bss` as `__asm__` blocks in the PS1's exact layout.
- `source/overlays/OVL/stage_table.inc`: the stage's chara table (`_StageCharacterEntries`) by symbol. `source/stage/OVL.c`
  includes it under `MGS_PORT` and keeps its original table for the matching build.

How it decides what is what:

- **Code end.** The code ends at the first referenced address past the last frame setup. Ending at the last `jr ra`
  failed in `s08b`, where a rodata word looked like `jr ra`.
- **Functions** start at frame setups, after a `jr ra`, and at addresses the code or data takes.
- **Data words** that point into the overlay or at resident code/data become symbols, so the data keeps working at
  the port's addresses. A word pointing into code counts as a function pointer if its target is a frame setup or
  follows a `jr ra`. Shortcut: a number that merely looks like a pointer is relocated too; the TAS replay is the
  check.
- **Jump tables** (found from the `lui`/`addiu` before a `jr`) keep their PS1 values: the translated `switch` compares
  against PS1 addresses.
- **Keeping the PS1 layout** means an address written as "label + offset" always lands on the right byte. That rules out a
  bug class that hand-split overlays had: statics placed differently in the port.

`CHECK=1 python3 tools/port/stage_split.py OVL` validates the splitter against an overlay the decomp has split.

## Step 2: translate

```
python3 tools/port/mips2c.py s10a 0x800C3208
```

It reads the stubs (from `asm/overlays/OVL/`, or `obj_ps2/stage_split/OVL/` for split-by-us overlays) and writes one
`.inc` per function. For decomp-split overlays, it also wraps each `#pragma INCLUDE_ASM` in the decomp's C files in
`#ifdef MGS_PORT #include "overlays/OVL/recomp/<func>.inc" #else ... #endif`.

The C is a literal transcription. Each MIPS register is `r[n]`, and the function has a private stack buffer where the PS1
frame lives, so even reads of never-written slots see the frame's own bytes. A sample:

```c
int G_s10a_800D7F38(int a0, ..., int a11) __asm__("s10a_800D7F38");
int G_s10a_800D7F38(int a0, ..., int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    ...
    r[4] = (u)0 + 16; CALL(R_GV_RandS);
    *(int *)((u)r[16] + 1808) = r[2];
    ...
    RECOMP_RETURN;
}
```

Details that matter:

- **Names.** Each function is defined under its asm name (`__asm__("s10a_800D7F38")`) with a `G_` C name, and every
  symbol it references is an `extern char R_x[] __asm__("x")`. That way the C names never clash with the including
  file's declarations.
- **Branches** become `goto`. A delay slot is emitted before the jump, except where the branch condition is computed
  first (`c = ...; <delay slot>; if (c) goto`).
- **Jump tables** become a `switch` on the loaded PS1 address with one `case` per target.
- **Addresses** built with `lui`/`addiu` become `(int)R_symbol + offset`.
  - A `lui` carries into a branch's delay slot target, an address seen once is reused on other paths, and a register's
    `lui` is forgotten at a call (caller-saved registers).
  - "Word symbol + offset ≥ 4" prints a warning: it is usually a static of another object that the map doesn't name.
    The fix is to make that variable `STATIC` (global in the matching build, so the map names it), as `s07b`'s
    `chair_alive` etc.
- **GTE instructions** (`mfc2`/`mtc2`/`cfc2`/`ctc2`, `lwc2`/`swc2`, commands) go to the HAL's software GTE
  (`Gte_DataRead` etc.).
- **Renames at calls.**
  - `mts_get_tick_count` → `Port_GameTick`: in TAS replays, game logic reads the PS1's tick (`host:tas_ticks.bin`).
  - `NewShadow`/`NewShadow2` → `Port_NewShadow*`: the struct-by-value wrappers below.

## Step 3: link

`build/overlays_ps2.py` links each overlay with `ld -r` and brackets its `.data`/`.bss` with
`Port_Ovl_<ovl>_data`/`_bss` symbols. On each load of the stage, `Port_SetStage` restores the `.data` to its first-load
snapshot and clears the `.bss`, as the PS1's reload from disc does. Then the matching builds must still pass (80 OK, and
2 OK with `--variant=vr_exe`), and the TAS replay is the real test:

```
python3 tools/port/tas/run_port.py --no-shots --last <loop> --seconds <s>
```

## The ABI rules (where translated code meets C)

Translated code keeps the PS1's calling convention (o32: 4 argument registers, then the stack from `sp+16`). The C it
calls uses the EE's, which passes 8 arguments in registers. `recomp.h` bridges the two, but the following cases each cost
a desync or a crash before they were handled.

1. **Every call passes 12 arguments.** `CALL(f)` passes `a0`–`a3` and the stack words at `sp+16..44`. `NewBulletEx` takes
   9 arguments; with 8 passed, Wolf's bullets got a garbage speed (Step 35).
2. **Every translated function takes 12.** `RECOMP_ENTRY` writes `a4`–`a11` back to `sp+16..44` above the frame, where
   the PS1 code reads its stack arguments. Its `stk` buffer has 48 bytes over the frame to hold them. `s10a`'s
   `800C5EF4` reads a 9th argument (Step 38).
3. **A `CALL` is never a sibling call.** With 12 parameters, GCC can compile a function's last call as a jump that writes
   arguments 9–12 into the function's own incoming argument area. A C caller that passed fewer arguments, such as
   `GV_ExecActorSystem` calling an `Act`, has no such area, so the write lands on its saved `ra`. `CALL` ends with an
   empty `__asm__ volatile("")` to rule this out (Step 38).
4. **Structs passed by value need a wrapper, in either direction.** The PS1 splits an 8-byte `SVECTOR` across two
   argument registers; the EE puts it in one 64-bit register. Every argument after it is then off by one.
   - Translated code calling C: `mips2c.py`'s rename table sends the call to a wrapper that takes the PS1's registers
     and rebuilds the struct (`Port_NewShadow`, `Port_NewShadow2` in `chara/snake/shadow.c`).
   - C calling translated code: `stage_split.py`'s `ABI_WRAP` points the stage table and data at a wrapper that takes
     the struct as C passes it and calls the translated function with the PS1's registers (`Port_s10a_DemoKage` in
     `port/src/hal_game.c`, for `demoexec.c`'s `DEMOID_SHADOW` call).
   - To find candidates when adding an overlay, list the C functions its translated code calls and grep their
     prototypes for struct parameters without `*`. Do the same for C function pointers the overlay's table entries are
     called through (`demoexec.c`'s `funcptr` is unprototyped). Today only the shadow functions are affected.
5. **Return values** come back in `r[2]` (`RECOMP_RETURN`); 64-bit and struct returns aren't handled.

## PS1 behaviours the translated code relies on

The translation is exact, so code that depends on the PS1's memory map breaks in the same places as the hand-decompiled
C. Collect every "TLB Miss" PC from a PCSX2 run (`grep -a "TLB Miss" obj_ps2/run_port.log | sort | uniq -c`) and fix each
one; never dismiss them.

- **Reads through NULL.** The PS1 has RAM at address 0, holding BIOS bytes, and doesn't fault. Find the field's owner by
  logging it in the port, dump the same Work on the PS1 (`work_dump.lua`, `ram_dump.lua`), and compare.
  - A port bug, as `s07b`'s Mantis shadow flag was: fix the cause.
  - A real PS1 NULL read: give the code what the PS1 read. The Ninja afterimage's light position is the BIOS bytes at
    0, (3, 0, 3152); `DummyPlayer` got a zeroed map.
- **Bit 31 of pointers.** PS1 pointers are `0x80xxxxxx`, and code uses the bit as a tag. The HZD wall/floor tag now goes
  through `HZD_IS_WALL`/`HZD_TAG_FLOOR`/`HZD_UNTAG_FLOOR` (`libhzd.h`; the port tags floors with the EE's uncached
  mirror, `| 0x20000000`). Grep a new overlay's translated code for `& 0x80000000`, `< 0` tests on pointers, and calls
  of `HZD_GetOnlineHazard`.
- **The mts tick.** Code that reads `mts_get_tick_count` for game logic (Wolf's `rand()` burn) gets the PS1's tick in
  TAS replays. A tick read partway through a long loop may need a `TICK_AT` entry in `trace_to_pads.py` (Step 34).

## Debugging a translated overlay

- `Port_RecompLast[8]` holds the last 8 translated functions entered. A temporary `printf` of `__func__` in
  `RECOMP_ENTRY` from a given loop shows the chain before a crash.
- Logging the `rand()` callers with `__builtin_return_address(0)` (in `GV_RandU`/`GV_RandS`, or the HAL's `rand`) plus
  `addr2line` finds the extra or missing draw at a seed desync.
- On the PS1 side, BizHawk checkpoints (a state every 1,000 loops; `checkpoints.lua`, `seek.lua`) make each query about
  50 s:
  - `work_dump.lua`: an actor's Work at given loops;
  - `actor_list.lua`: the actor lists;
  - `ram_dump.lua`, then `ram_diff.py PS1_RAM PORT_RAM OVL` against the port's `host:tas_ramdump.txt` dump: whole-RAM
    comparison by symbol.

  BizHawk's memory write/execute callbacks don't work on this core.
- Revert temporary instrumentation before committing: `git status` should show only the intended files.

## Adding the next unsplit stage

1. `python3 tools/port/stage_split.py OVL`, then `python3 tools/port/mips2c.py OVL 0x800C3208`.
2. Read `mips2c.py`'s warnings ("word symbol + offset") and make the named statics `STATIC`.
3. Check the ABI rules: struct-by-value calls both ways (add to the rename table or `ABI_WRAP`), and tests of bit 31 on
   pointers. `mips2c.py` handles two cases itself: the wall/floor test right after `HZD_GetOnlineHazard` (the port's
   `0x20000000` floor tag), and `lui 0x1f80` (the port's scratchpad through `PSX_ADDR`).
4. Build both matching variants, run the TAS replay through the stage, and collect TLB-miss PCs.
5. Regenerating must reproduce the committed files: re-run both tools and check that `git diff source/overlays/OVL`
   is empty.
