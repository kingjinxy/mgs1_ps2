# Running Walkthrough — MGS Integral PS2 port

Dated log of how each change was made and what was tried. The plan is `Planning Doc.md`; HAL work is logged in
`../psx-to-ps2-HAL/docs/Walkthrough.md`.

## Step 1: the main executable compiles for the EE (2026-10-27)

`build/build_ps2.py` compiles the main executable's C files (the objects `linker_command_file.txt` lists before
its overlay sections: 219 files, all C) with ps2dev's GCC under `-DMGS_PORT -DINTEGRAL` into `obj_ps2/` (one
`.log` per file). The matching build (`build.py`, `obj/`) is untouched.

Flags, as the SH1 port settled on for decompiled PS1 code: `-O2 -G0 -std=gnu89 -nostdinc`, NULL reads stay reads
(`-fno-delete-null-pointer-checks -fno-isolate-erroneous-paths-dereference`), loops keep their counts
(`-fno-aggressive-loop-optimizations`), `-fno-toplevel-reorder`, GCC 14's new errors for old C downgraded.
`-fexec-charset=EUC-JP` does what the PS1 build's `convjp.py` step does (string literals UTF-8 -> EUC-JP; checked
byte for byte against Python's encoder).

Include order: `port/include` (the port's shims and generated headers), the HAL's `include`, `source`,
`source/include`, then Sony's stock PSY-Q 4.4 headers (`../psyq_sdk/psyq_4.4/include`), as the PS1 build uses.

**GTE macros.** MGS uses Nugget's no-DMPSX `inline_n.h` and its own `inline_x.h` (raw COP2 inline asm, which the
EE can't run). The SH1 port's generator moved to the HAL (`tools/gen_gte_inline.py`, now with
`<source>=<output>` arguments; SH1's `tools/port/gen_gte_inline.py` is a wrapper; its output is unchanged but for
the comment line) and learned Nugget's `cop2 <command>` form (and `cop2 %0`, for `gte_mvmva_core`):
`port/include/gte_from_inline_n.h` (243 macros), `gte_from_inline_x.h` (10), `gte_from_radar.h` (radar.c's two
local macros). `port/include/inline_n.h`/`inline_x.h` are shims: `#include_next` the game's header, then the
translation. The game's headers have no include guard and are included more than once, so the shim clears the
generated header's guard first: otherwise a second inclusion put the asm versions back (5 files failed on
`mtc2`/`swc2` until then).

**Source changes, all under `MGS_PORT`** (matching build: 80 OK, and the VR executable):
- `mts/mts_new.h`: `mts_assert` takes the existing C99 variant (GCC rejects `printf( ##args )`).
- `mts/mask.c`: `SetExMask`'s `break 1030` left out (the EE assembler has no single-operand break code above
  1023; a debug trap).
- `menu/radioanim.c` (`OFFSET_TO_PTR2`), `takabe/thing.c`: casts as lvalues written as stores through a pointer.
- `libfs/cdstage.c`: the `extern` declarations before the `static` definitions left out.
- `enemy/action.c`: `s00a_off_800C33F4` points to writable arrays (the code writes digits into these strings;
  string literals are shared and read-only to GCC).
- `menu/radar.c`: its two local GTE macros from `gte_from_radar.h`.
- `include/psxdefs.h`: `SetSpadStack`/`ResetSpadStack` are no-ops (they moved the stack into the PS1 scratchpad at
  0x1F8003FC; only a speed trick, and the address isn't the scratchpad on the EE).

Result: 219 of 219 compile. Warnings left: 1118 `-Wbuiltin-declaration-mismatch` (PSY-Q's prototypes of C library
functions), one `-Woverflow` (PSY-Q's `termPrim` storing 0xFFFFFFFF in a 24-bit field, intended).

## Step 1: linked; boots to MGS's main() in PCSX2 (2026-10-27)

`build/link_ps2.py` compiles the game (`build_ps2.py`), the HAL's sources and MGS's side of it (`port/src/`), and
the HAL's IOP modules (embedded with `bin2c`), links them against ps2sdk into `obj_ps2/mgs.elf`, and puts that on
a DVD image, `obj_ps2/mgs_ps2.iso` (the HAL's `tools/mkiso.py`, copied from the SH1 port). Overlays aren't linked.

**The file list was wrong before.** `build_ps2.py` stripped the jinja tags from `linker_command_file.txt`, which
kept *both* branches of every `{% if %}`: the 219 files included the VR `sna_init` and 50 dev-only files. It now
reads the matching build's rendered `obj/linker_command_file.txt` (main_exe variant): 168 files. One line there
has no closing quote (`libhzd\navigate.obj`): the pattern allows that.

Game objects linked together:
- **Duplicate definitions** of variables defined in several files (`GM_StageName`, `GM_CurrentPadData`, ...):
  common symbols to the PS1's GCC. `-fcommon`, and `SECTION(x)` is empty under `MGS_PORT` (`mgstype.h`): a
  variable with a section attribute can't be common.
- 156 undefined names, all PSY-Q or C library, plus `_bss_orgend` (the PS1 executable's end of BSS, where
  `mts_get_bss_tail` points): for now the ELF's end of BSS (`port/linkfile`). Where the PS1's heaps go is Step 2.
- The game's `main` becomes `Game_PsxMain` (the HAL's `main` calls it).

The HAL's generic sources include `common.h` (SH1's types and PS1 memory macros) and `<psyq/...>`: MGS gives them
`port/hal/common.h`, `port/hal/hal_game_config.h`, an empty `port/hal/port/prof_game.h`, and `obj_ps2/hal_inc/psyq`
(a link to the PSY-Q 4.4 headers), on their include path only. `long` is 32 bits on the EE (EABI), so PSY-Q's
structures keep their layout. Left out: the HAL's `libcd_ps2.c` (SH1's disc; decision B), `psx_card.c` and
`memcard_ps2.c` (the card mapping isn't done). The 24 names nothing defines yet get generated stubs that log
their first three calls (`obj_ps2/hal_stubs.c`): libcd, libcard and the BIOS card file calls, and `PadInitDirect`,
`PadStartCom`, `PadStopCom`.

Getting it to run:
1. **The zero page was mapped in PCSX2.** The crash reporter tells PCSX2 from hardware by looking for
   `host:sh1_ps2.iso`; MGS has none, so it mapped addresses 0-0x1FFF to a page of zeros as on hardware, and
   PCSX2's "TLB Miss" lines for NULL reads would have gone. The probe file is now a setting,
   `HAL_GAME_HOST_PROBE` (HAL `crash_ps2.c`; SH1's file is the default): `mgs.elf` here.
2. **TLB misses in `mts_boot` and `mts_VSyncCallback`** (loads at 0x108/0x110): `mts` reads the PS1 kernel's
   Table of Tables at 0x100 (each thread's TCB, to set its SR; the current-TCB entry, which `mts` rewrites from
   the vertical blank interrupt to switch tasks). Under `MGS_PORT` both go through `Port_PsxToT()`, the HAL thread
   layer's copy of those tables, which already handles the interrupt switch.
3. **A hang in `SifExecModuleBuffer` (the HAL loading `sh1agent.irx`).** The game defines `fprintf`, `getchar`,
   `random` and `sio_puts`, which ps2sdk and newlib also have; the game's definitions won the link, so library
   code called them. `link_ps2.py` now finds every name the game and the linked libraries both define and renames
   the game's (`MGS_<name>`, its own calls follow). The retail build's `printf` is an empty function (only the dev
   executable prints): left out under `MGS_PORT`, so the game's messages reach the console. (Until then only the
   HAL's plain-string prints came out: GCC turns those into `puts`.)
4. MGS prints its boot steps without newlines (`mem:`, `pad:`, ...): `HalGame_Init` (`port/src/hal_game.c`)
   makes stdout unbuffered, as the PS1's printf is. `MGS_LOG_DIRECT=1` sends console output straight through
   instead of via the HAL's log thread (which the vertical blank handler wakes): for debugging early hangs.
   Booting the ELF from `host:` or from the disc image made no difference to the hang in item 3; the image is
   kept, as SH1 tests run that way.

Now (PCSX2, from `mgs_ps2.iso`): the HAL starts, `mts` prints its banner (`Multi Task Scheduler for PSX ver2.02`)
and starts its system task and the game task, `Main` calls `ResetGraph` and friends, the display comes up
(320x240p), and `memcard_init` waits for card events that the stubbed libcard never sends. No TLB misses. Next:
the memory card mapping (Step 1), then the pad, then the CD replacement once the disc images are here.

Matching build: 80 OK, and the VR executable. SH1 links unchanged (9 stubs).
