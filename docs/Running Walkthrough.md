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

## Step 1: the memory card (2026-10-27)

The HAL's PS1 card layer (`psx_card.c`: libcard and the BIOS file calls over one PS1 card image per slot,
kept in a save folder on the PS2 card by `ps2/memcard_ps2.c`) is now linked:
- `memcard/memcard.c` maps `open`/`close`/`lseek`/`read`/`write`/`firstfile`/`nextfile`/`erase`/`format` to the
  HAL's `Port_Bu*` under `MGS_PORT` (the plain names are the PS2 C library's), as SH1's `memcard.c` does.
- Settings (`port/hal/hal_game_config.h`): PS1 product `BISLPM-86247` (the game's `MGS_MemoryCardName`), PS2 save
  folder `BISLPM-86247MGS`, icon file `MGS.ICO`, title "METAL GEAR SOLID / PS1 saves". The line break of the
  title was fixed at SH1's 11 characters: now `HAL_GAME_PS2_SAVE_TITLE_BREAK` (default 11), 16 here.
- The save icon: the HAL takes a 16x16 4-bit TIM. MGS keeps its icons as raw CLUT + pixels
  (`clutsAndIcons_8009E774` in `menu/datasave.c`); `HalGame_Init` puts Snake's (the first) into a TIM,
  `g_MgsSaveIconTim`.
- `MGS_MC_FORMAT=1` builds format an unformatted card in port 1 and copy each PS1 image written to
  `host:cardN.mcd` (the HAL's `SH_PORT_MC_FORMAT`): for PCSX2 runs with `pcsx2_run.py --memcards <empty folder>`.

**`memcard_init` hung.** The HAL answers `_card_info` asynchronously: the PS2 card query runs in the background and
its event is delivered from `TestEvent` (SH1 polls its card events that way every frame). MGS never calls
`TestEvent`: its events' callbacks set flags that it waits for in `mts_wait_vbl` loops, so the answer never came.
New HAL setting `HAL_GAME_CARD_INFO_WAIT` (set for MGS): `_card_info` runs the query to its end
(`PortMc_InfoWait`) and delivers the event at once, as the PS1 BIOS's interrupt would have. MGS queries the card
from its boot and the data screen, not every frame, so the wait doesn't cost frames. (Deciding by thread
instead didn't work: `memcard_ps2.c` takes its "main thread" from its first caller, MGS's game task.)

Now (PCSX2, a fresh card in port 1, none in port 2): port 1's card is found and reported as new
(`*** sw card new`, as on the PS1 at boot), its image starts empty (no save folder yet); port 2 times out
(`[C.S.T.O]`, no card). The game goes on to `pad:`, `gv:`, `fs:` and then waits on the stubbed libcd. Saving and
loading can be tried once the game runs that far (the disc).

Matching build: 80 OK, and the VR executable. SH1: links (9 stubs); 150 s in PCSX2 into its demo loop, card found
and its image loaded, no TLB misses.

## Step 1: the pad (2026-10-27)

MGS's pad code (`mts/mts_pad.c`) uses `PadInitDirect`/`PadStartCom`: the PS1 BIOS writes each pad's data into the
game's two receive buffers every vertical blank, and the game's vertical blank callback (`do_control`, through
`mts_VSyncCallback`) reads them, checks the pad state and sets up the DualShock's actuators (`PadInfoAct`,
`PadSetActAlign`). SH1 never calls these (its `Joy_Init` opens the PS2 pads itself), so they were stubs.

HAL (`ps2/libpad_psx.c`, `ps2/pad_ps2.c`):
- `PadInitDirect` keeps the two buffers, `PadStartCom` opens the ports and has every poll copy the pads' 8-byte
  records into them (`Port_PadSetDirect`), `PadStopCom` (the soft reset) stops the copies.
- **First run crashed** (jump to `0x657A696C`, ASCII "lize", right after the first pad poll). The HAL runs the
  game's vertical blank callback in the interrupt; MGS's calls `VSync(-1)` there, and VSync polls the pads
  (libpad, IOP calls, printf). Until then the ports were never open, so the poll returned at once. Bigger task
  stacks (tried first: the system task's is 512 bytes) didn't help. New HAL setting `HAL_GAME_PAD_THREAD`
  (set for MGS): the vertical blank interrupt wakes a thread that polls (priority 2, above the game's), VSync
  doesn't poll, and the calls the callback makes answer from the last poll (state, actuator info) or are left
  for the next one (`PadSetActAlign`, `PadSetMainMode`). The actuator info is read once per plugged-in pad:
  each `padInfoAct` is a pad command, and reading them at every state change kept port 1 alternating between
  "executing" and "stable" every frame.
- `PadGetState` mapped the PS2's states to the wrong PS1 values: a command in progress gave 2
  (`PadStateFindCTP1`, a pad without DualShock functions) and a pad without them gave 6. MGS then marked a
  DualShock as digital. Now: FINDCTP1 → 2, EXECCMD → 5, STABLE → 6 (`libpad.h`'s values).
- `mts_new.c` under `MGS_PORT`: every task runs on a 32 KB stack of the port's (`mts_port_stacks`); the PS1's
  0.5–2 KB stacks are left in place with their cookies. Kept although it wasn't the crash: EE frames are
  larger than the PS1's, and the system task now runs HAL code.

Now (PCSX2): port 1 goes stable, the actuator alignment is sent, no TLB misses; the game waits on the stubbed
libcd as before. Buttons can be checked once the game gets past the disc. Stubs left: the libcd functions.

Matching build: 80 OK, and the VR executable. SH1: links (9 stubs); 150 s in PCSX2 through its attract demos, pad
stable, no TLB misses.

## Step 6 (early): the PS1 disc on the DVD, and libfs's reads (2026-10-27)

The user supplied the Integral discs as CHDs in `ps1-original/` (gitignored, never committed). Each disc is one
MODE2_RAW data track, no audio. `build/link_ps2.py` extracts discs 1 and 2 with `chdman extractcd` (once, or when
a CHD is newer) to `obj_ps2/ps1/DISC1.BIN`/`DISC2.BIN`, raw 2352-byte sectors, and puts both on the DVD image
next to the ELF and SYSTEM.CNF (~1.47 GB, single layer). The VR disc is left out for now.

The game counts sectors from MSF 00:00:00 (`srchfile.c` adds 150 to ISO9660 LBAs), so PS1 sector n is at byte
(n - 150) * 2352 of the file, its data 24 bytes in (sync, header, subheader).

`libfs/cdbios.c` under `MGS_PORT` (the planning doc said this was written in Step 1; it wasn't): the cdbios task
keeps its request/stop/start flags, but instead of `CdlReadN` + a ready callback it reads chunks of 16 sectors
through `port/src/cdbios_ps2.c` (`sceCdSearchFile("\DISC1.BIN;1")`, async `sceCdRead` into a bounce buffer,
`sceCdSync(1)` polled once per vertical blank, data cache invalidated after the DMA as in the HAL's
libcd_ps2.c) and hands each sector to the same logic as `CDBIOS_ReadyCallback`: copy, request callback,
callback 0 stops, 2 doesn't advance the buffer. The header's MSF is checked against the expected sector. A request
started from inside a callback ends delivery of the chunk. On the PS1 the callback ran in an interrupt; here each
sector is delivered in `SwEnterCriticalSection` (HAL: plain DI/EI, not nestable, so one per sector). The stream
callback stops itself when its buffer is full, so ~6x the PS1 drive's rate is safe. `CdInit`/`CdReset` find the
file.

Found on the way:
- The directory's file sizes came out negative: `read_lsb_ulong` on `char` bytes >= 0x80. PSY-Q's `ccpsx` treats
  `char` as unsigned (SH1's build passes `-funsigned-char` too); `build_ps2.py` now does. This affected all game
  code, not only libfs.
- `srchfile.c` printed `found->pos` with `found` NULL for the executable's entry: guarded under `MGS_PORT`.

Then the game read STAGE.DIR's table into `MEM_ADDR` (0x80117000), which on the EE is kseg0 → physical 0x117000,
the port's own code: `FS_MovieFileInit` was overwritten and the EE ran ASCII. That's Step 2.

## Step 2: fixed addresses (2026-10-27)

`tools/port/find_fixed_addresses.py` (from SH1, scanning `source/`): 4585 literals. Split by range: the
scratchpad and RAM from `MEM_ADDR` up are buffers (heap, pack/load buffers, stack values); 0x80010000 up to
`MEM_ADDR` are addresses of code/data symbols, almost all in overlays (jump tables, `NEWCHARA` tables, `const int`
dwords), which need real symbols in Step 3 (`--symbols` lists them). Buffers: 102 scratchpad, 11 RAM.

`PSX_ADDR(literal)` (`source/include/psx_mem.h`, included by `psxdefs.h`): the literal in the matching build, the
same offset in the HAL's existing arenas (`g_PsxRam` 2 MiB, `g_PsxScratch` in the EE scratchpad) in the port. It
stays an integer, so the wrap is mechanical: casts, compares (`divide.c`'s `rvec < 0x1f800254`) and `gte_*`
arguments are unchanged. Applied with a one-off script (the first regex skipped literals right after `(`; a
second pass caught them). `SCRPAD_ADDR` and PSY-Q's `getScratchAddr` (shim `port/include/libetc.h`) go through
it. `brf/overlay2.c`, `sd_main.c` and `mask.c` needed the include.

Then "Resident Memory Over" on every allocation: `StageCharacterEntries` (the overlay area, resident memory's
lower limit) is `mts_get_bss_tail()`, the ELF's bss end (~0x738000), above the arena. It now returns
`PSX_ADDR(0x800C3208)`, the PS1's `_bss_orgend` (obj/asm.map), so the overlay area stays below `MEM_ADDR` as on
the PS1.

NULL reads at `memcpy` (32 bytes from 0): found by temporarily wrapping `memcpy`, then `LoadImage`, with
`-Wl,--wrap` and printing `__builtin_return_address` for low sources. Menu panel textures (`weapon.c`) are uploaded
before `item.rpk` is cached, from address 0 on the PS1 (BIOS memory). Guarded under `MGS_PORT`.

Now: init stage, then `title` loads; no TLB misses. The EE stopped ~13 s into the title stage with no message.
Tried: delivering sectors without the critical section (same stop at the same frame, so not that). It was the
title overlay's code, which couldn't run yet.

`radiofacedraw.c`'s codec noise reads the PS1 executable's code at 0x80010000 as a texture; through the arena it
reads that part of `g_PsxRam`, likely zeros. To check against DuckStation.

## Step 3: the overlays linked into the executable (2026-10-27)

The user chose SH1's route: overlays built into the executable (the PS2 has the RAM), back to loaded overlays only
if memory runs short.

`tools/port/overlay_survey.py`: per overlay, its objects (from the rendered `obj/linker_command_file_<ovl>_lhs.txt`),
`INCLUDE_ASM` stubs (written `#pragma INCLUDE_ASM`; the first regex missed them) and literal code/data addresses
(0x80010000 up, so `0x80000000` flag bits don't count). 59 of the 79 built overlays are clean.

`build/overlays_ps2.py`, called by `link_ps2.py`: compiles the clean overlays' sources like the main executable,
`ld -r`-merges each overlay, applies the main game's `MGS_<name>` renames, renames `_StageCharacterEntries` to
`_StageCharacterEntries_<ovl>` and makes every other defined symbol local (`objcopy --keep-global-symbol`). Shared
objects get their own copy and data per overlay, as on the PS1. Generated `obj_ps2/ovl/stages.c` lists the tables
by stage name. PSY-Q library objects in the overlay lists come from the HAL. No clashes; ELF ~8 MB.

Hook: `game/chara.c` `Port_SetStage(id)` picks the table whose `GV_StrCode(name)` matches the id's low 16 bits;
`GM_GetCharaID` searches it instead of `StageCharacterEntries`, and `GM_ResetChara` switches to an empty table
(rather than writing an end marker into the static table). Called from `GM_LoadInitBin` first, but that loader
never runs for stage overlays: `cdstage.c` reads a `.bin` tag straight to `StageCharacterEntries`. The call there
is the one that matters. The binary is still read into the arena, unused.

Compile failures: `searchli.c`, `envmap3.c`, `libdg2.c`, `sub_efct.c` define their own GTE asm macros
(`mtc2`/`mfc2`, not on the R5900). Translated with the HAL's `gen_gte_inline.py` into `port/include/gte_from_*.h`,
included under `MGS_PORT` after the macros. `libdg2.c` has four groups of macros, each used before the next is
defined: the translation is included after each group, its guard `#undef`'d first (as the `inline_n.h` shim does).

`title`/`change` include `safechk.obj` (asm only): Sony's copy protection. `SafetyCheck` passes, and
`CdControl`/`CdControlB` report "standby, shell closed" (`port/src/cdbios_ps2.c`, with `CdIntToPos`: libcdvd's
header has a macro of that name, `#undef`'d).

Title: `card1 = *memcard_files(0)` with a new card (checked usable, but its last operation wasn't a read, so
NULL): the PS1 copied from address 0. `open.c` now uses `MEMCARD_FILES(port)`, an empty card for NULL in the port.

Now (PCSX2): Konami logo → title (memory card check) → `opening`, whose 3D scene renders (~1400 prims a frame);
120 s, no crash, no TLB misses. Frame dumps: `MGS_DUMP_FRAMES=1 python3 build/link_ps2.py` (HAL
`SH_PORT_DUMP_FRAMES`, frames 30-2400 to `obj_ps2/`). New stubs: movie streaming (`CdRead2`, `St*`, `CdReady`),
`select`'s `PCcreat`/`PCwrite`.

Matching build: 80 OK, and the VR executable.

## Step 3: intro and new game crashes (2026-10-27)

Reported: the intro went black after "Konami Computer Entertainment Presents"; waiting on the title started it but
it crashed soon after; New Game froze on a black screen.

**Intro: thread switch inside `ChangeTh`'s window (HAL).** Reproduced (hang right after `NewStream 2970`). Temporary
prints in `libfs/stream.c` and `game/strctrl.c` showed the stream reads and the stream actor running normally. Then:
NULL TLB misses in `mts_wait_vbl` and `assertion faled : mts_new.c line 657 : Task 1` (task 1 = `MTSID_SOUND_INT`).
The voice stream's SPU interrupt (`sd_str.c` → `mts_isend(MTSID_SOUND_INT)`) is delivered by a HAL thread; mts
made the sound task current, but the HAL (`thread_ps2.c switch_check`) deferred the switch to the next vertical blank
when it came between a `ChangeTh`'s wakeup and its sleep. The `ChangeTh` target ran meanwhile, mts believing it to be
the sound task, and called `mts_wait_vbl` with task 1's NULL `intr`. The deferral had been tested with
`tools/thread_test` only for the timing of the switch, not for what the woken thread does in between. Now the switch
is made at once: the target (woken, maybe not run yet) is suspended like any thread an interrupt takes the CPU from;
if the new thread is the `ChangeTh` caller, its pending wakeup makes its `SleepThread` return at once.
`thread_test` updated (window switches now come back on the vertical blank after asking): PASS twice. The whole intro
(three demo streams) then plays and returns to the title.

**Scripted pad input for PCSX2 runs** (`port/src/pad_script.c`): `MGS_PAD_SCRIPT="from-to:buttons,..."` at link
time, buttons in `libgv.h` `PAD_*` bits (0800 START, 0020 Circle), vertical blanks from `mts_get_tick_count`;
`mts_pad.c do_control` clears them from the state it reads. Failed first: `strtoul` in the parser crashed the EE
(kernel TLB misses; `do_control` runs in the vertical blank interrupt), now parsed by hand; a poll counter didn't
advance with time; the bits were first taken as the raw pad bytes (START 0008), which the game ignores.

**New Game: proc id vs block address.** `GCL_ExecProc` got `0x7EB076` (`PROC ... NOT FOUND`, NULL+3 read in
`GCL_ExecBlock`), from `game/delay.c`: a delayed command holds a proc id or a script block's address and tells them
apart by the sign, as PS1 addresses are 0x80xxxxxx. Same in `game/item.c` (an item's end proc). `libgcl.h`
`GCL_IsBlock(v)`: `v < 0` on the PS1, above 0xFFFF (proc ids are 16 bits) in the port. Other sign tests on procs
(`script.c` `DemoCmd`, `strctrl.c`) test the `STATE_DEMO` flag ORed into an id, which is fine.

**Dock NULL reads**: `sna_init.c` reads `*field_918_n_bullets` every frame, NULL with no weapon in hand;
`script.c` `FuncCmd 's'` reads `GM_PlayerControl` before Snake exists (`s00a`'s scenario). Both read PS1 kernel RAM
at 0 there; guarded under `MGS_PORT`.

Now (PCSX2, START, START, Circle): title → `d00a` (briefing, its stream plays and renders) → `s00a`, the dock's
codec call on screen and waiting for a button; 120 s, no TLB misses. Matching build: 80 OK, VR 2 OK.

User's run (2026-10-27): the game gets through the dock's codec call into gameplay. (The scripted run stopped at
the codec only because its presses ran out.) Next: how far gameplay holds, and the heliport (`s01a`).

## Step 5: frame comparison with DuckStation; the opening's underwater background (2026-10-27)

Reported (user): the intro cutscene's graphical effects looked wrong, especially the "underwater" effect.

**`tools/port/compare_frames.py`**, after SH1's: DuckStation (software renderer, muted, GDB server) runs the
Integral disc 1 CHD; `tools/port/gdb/capture_ps1.py` waits for `NewLoader("opening")` (`--stage`) and counts
frames in `DrawOTag` calls from there. Per captured frame it writes the VRAM *before* the frame (SH1 took only
the end state and redrew over it, wrong for effects that read the frame buffer in place), every GPU command of
the frame (ordering table, `PutDrawEnv`'s packet, and `LoadImage`/`MoveImage`/`ClearImage` as GP0 A0/80/02
commands), and the VRAM after. Addresses from `obj/asm.map`. Two PS2 modes (`port/src/capture_ps2.c`, through
`host:capture.txt` in `obj_ps2/`):
- replay (default): the PS1's commands drawn through the HAL's GS renderer from the PS1's VRAM: the renderer alone.
- `--live`: the port plays the stage and captures its own Nth `DrawOTag` (`Capture_Stage`, called from
  `game/loader.c`'s `NewLoader` under `MGS_PORT`): the whole game against the PS1.
Output in `obj_ps2/cap/`: `cmp[live]_N.png` (draw area, PS1 | PS2 | difference) and the counts. Each side is
cropped by its own drawing area: the port can be drawing the other half of the double buffer.

Failed first: the extracted `obj_ps2/ps1/DISC1.cue` named `DISC1.BIN.tmp` (`chdman`'s output name before the
rename), so DuckStation booted nothing and its GDB port never opened. The tool uses the CHD; `link_ps2.py` now
also fixes the cue's file name.

Results, opening frames 50-1600: **replay** is exact up to frame 400, then under 1.3% of pixels (single pixels on
polygon seams of the background gradient): the renderer was not the problem. **Live**: horizontal bright bands
over the underwater background (frames 600, 800, 1600), and 84 fewer 160x2 sprites than the PS1 at frame 600.
Those strips are `takabe/wt_view.c`'s water view (the scene re-drawn in wavy lines): `scratch2 = (short
*)0x1F800400` was never wrapped in `PSX_ADDR`, so one list went to the raw address and `count1` subtracted
pointers in two areas (wrong count, wrong `v0`). Two misses behind it, both at the scratchpad's end address:
`find_fixed_addresses.py`'s range stopped at 0x1F8003FF, and `PSX_ADDR` itself mapped 0x1F800400 to
`g_PsxRam + 0x400`. With only the wrap, the effect wrote downwards over `g_PsxRam` 0x32C-0x3FE (the PS1's
kernel area, used by the HAL) and the port jumped to 0 at the opening's first frame. Now `PSX_ADDR` takes
0x1F800000-0x1F800400 as the scratchpad, and the tool reports that range (nothing else unwrapped). The other two
0x1F80xxxx literals (`takabe/libdg2.c`) are inside a comment; the `rank` overlay's are hardware registers, and
that overlay isn't linked.

Now (PCSX2, live): the bands are gone; frames 600/1300/1600 match the PS1 by eye. The pixel differences left
(20-30%) are timing: the port is one frame off in the double buffer's parity (`GV_Clock`, which also sets the
wave's phase), and the sub interior's camera is slightly further along. No TLB misses through frame 1600.
Matching build: 80 OK, VR 2 OK.

## Step 5: cutscene timing locked to the PS1's for comparisons (2026-10-27)

Goal: the port's frame N shows the same moment as the PS1's frame N, so `compare_frames.py --live` measures the
port, not timing. Measured first (`GV_Time`/`GV_Clock` printed at each capture on both sides):
1. **Cutscenes follow a clock, not frames.** `kojo/demothrd.c` `ActStream`: demo frame = `(FS_StreamGetTick() -
   start) / 2`, and `FS_StreamGetTick` (`libfs/stream.c`) is the voice stream's SPU counter, or vertical blanks
   when there's none. The PS1 runs about 2.5 ticks a loop, unevenly. Now `capture_ps1.py` records the tick
   `ActStream` got on every loop (breakpoint after its call, 0x80079680), in `ps1_ticks.txt`. In comparison runs
   (`ticks` in `capture.txt`), `FS_StreamGetTick` returns the PS1's tick for that loop (`Capture_Tick`, under
   `MGS_PORT`). Sub interior frame 1000: 7208 → 58 differing pixels.
2. **`DrawOTag` calls aren't loops.** The PS1 ran `ActStream` three times before the stage's first `DrawOTag`.
   Frames are now game loops (`GV_Time`) from the end of the stage's load (`FS_LoadStageComplete`, the loader's
   `Die`; `Capture_LoadEnd` on the port), captured at the first `DrawOTag` of loop N or later. Tried first:
   counting from the load's end in `DrawOTag`s. No difference, because nothing is drawn during the load.
3. **The wait for the stream's first data is the CD's.** The PS1 started the stream's clock 31 loops after the
   load, the port 7. Loop-counting actors saw that gap: `takabe/wt_view.c`'s `n_prims` (the wave's phase) was
   24 loops off, which is the 16-line shift of its strips. `strctrl.c` state 2 now waits for the PS1's loop
   (`Capture_StreamMayStart`) in comparison runs.
4. **Double-buffer parity** (`GV_Clock`, which picks the buffer the water view samples) is inherited from boot.
   At the load's end, if it differs from the PS1's (recorded in `ps1_ticks.txt`), `gvd.c` skips one flip
   (`Capture_HoldClock`, the same skip `DG_HikituriFlag` makes).
All of these hooks do nothing without `host:capture.txt`.

Result (opening, loops 50-1600): frames 50, 400, 600, 800, 1000 and 1600 now have identical GPU commands on both
sides, once padding the GPU doesn't read is masked (the upper halves of a textured polygon's third/fourth UV words
and the CLUT of 15-bit sprites hold PS1 stack garbage). Their pixel differences (0-3%) are the renderer's seam
pixels, as in replay mode. Loop 1300 (sub interior) still differs in the vertex colours of 75 lit polygons: a
game-side difference (lighting, or a random flicker), not investigated yet. Matching build: 80 OK, VR 2 OK.

## Step 6: deploying to the console, alongside Silent Hill (2026-10-28)

The user deploys SH1 to their PS2 over Ethernet (Neutrino from a USB stick, its UDPFS server on the PC). The two
games would have collided in four places: Neutrino's server listens on a fixed UDP port (0xF5F6) and serves one
folder; the stick's Neutrino config names one image (`default_dvd = "udpfs:sh1_ps2.iso"`); both games broadcast
their log to UDP 18194 and run the same IOP agent (62968), and SH1's `build-and-deploy` found "its" server with a
pattern an MGS server would match; and the HAL's restart (`crash_ps2.c` `RELAUNCH_ELF`) booted SH1's
`SHPS_000.01`. The user chose to serve both at once:
- **One server, in the HAL** (`tools/udpfs_serve.py`, from SH1's wrapper): serves `~/ps2serve/`, which holds a
  symlink per game to its image. Neutrino's server refuses paths that resolve outside its folder, so the wrapper
  also accepts a symlink placed directly in the folder (tested: the image resolves, `../` paths are still
  refused). Deploy flag: `~/ps2serve/.udpfs_refresh`.
- **One log receiver, in the HAL** (`tools/ps2_log.py`): `~/ps2serve/ps2.log`; `obj_ps2/ps2.log` and SH1's
  `build/port/ps2.log` link to it.
- **MGS:** `build-and-deploy` (builds, links `mgs_ps2.iso` and the log, starts the shared server and receiver or
  deploys), `tools/port/ps2_ctl.py` (SH1's, the generic commands only: ping, restart, deploy, osd, md, where),
  `RELAUNCH_ELF` = `cdrom0:\MGSP_000.01;1` in `port/hal/hal_game_config.h`, and `obj_ps2/usb/neutrino_mgs`
  (SH1's Neutrino folder, `default_dvd = "udpfs:mgs_ps2.iso"`) for the stick.
- **SH1:** `build-and-deploy` uses the shared server and receiver and links `sh1_ps2.iso`; `ps2_ctl.py` uses the
  shared flag. Each script stops SH1's old per-repo server/receiver, found by command line and working directory
  (they were started with relative paths).

Not tried on the console yet. A deploy restarts whichever game is running; to switch games, power-cycle and start
the other Neutrino folder. PCSX2: still boots to the opening, no TLB misses.

## Step 6: first boot on the console: hang in the opening (2026-10-28)

The user booted `neutrino_mgs` on the PS2 (shared UDPFS server, first MGS run on hardware). Log:
`docs/hardware/2026-10-28-opening-hang.log` (from this boot's first line to the watchdog).

Reached: Neutrino → `init` → `title` (memory card check: no saves) → `opening` at 16.7 s, its voice stream
started at 17.6 s (`NewStream 2970`), the opening's 3D scenes drawn (up to ~1600 prims a frame), no TLB misses or
crash reports.

**Hang at frame 2095 (log 80.2 s, about 63 s into the opening).** No new frame; the vertical blank interrupt and
heartbeat carry on; the HAL watchdog reported `no frame for 10 s (frame 2095); D6 CHCR 00000085`. The voice stream
then starves: `sd_str.c` prints `*` each time it has no data and plays silence (the first `*` in the log is at the
hang). Found with the console still in that state:
- `ps2_ctl.py ping`: EE idle in the kernel (pc 0x81fe0), the game thread "status 4 wait 1/25" (HAL thread asleep
  on semaphore 25), no SIF DMA in flight (IOP ch10 CHCR 0x701, EE ch6 0x85), IOP sending nothing to the EE.
- `ps2_ctl.py md mts_tasks_800C0C30`: mts thinks **GAME (3) and CDBIOS (10) are READY** while the active task
  (`mts_active_task_800C0DB0`) is **IDLE (11)**. SYSTEM and SOUND_INT receiving, SOUND_MAIN sleeping. A task switch
  was lost between mts and the HAL's threads: the scheduler has runnable tasks but the CPU stays in the idle task.
  Same family as Step 3's "thread switch inside ChangeTh's window" (`thread_ps2.c` `switch_check`), now on hardware,
  whose interrupt timing differs from PCSX2's.
- Not disc bandwidth: the UDPFS server served a steady ~110 KB/s from the stream's start, while the opening played
  normally, and after the hang alike (2.1 MB/s during the boot loads).

Next: reproduce in PCSX2 (opening played to the end, several runs) or with `tools/thread_test`; read the HAL
thread layer's state at the hang (which EE thread is current, the parked state of the GAME thread) through `md`.

## Step 6: second console run, cutscenes skipped; pad and audio findings (2026-10-28)

The user skipped every cutscene: `init` → `title` → `d00a` (briefing skipped) → `s00a`, through the dock's
codec call into gameplay, no crash or hang.

**Snake moved on his own.** No scripted presses were compiled in (`MGS_PAD_SCRIPT` unset). Read from the console
(`ps2_ctl.py md`): `padbuf_800C1480` held a digital pad (ID 0x41) with buttons `df ff`, Right held (active low),
and mts's `pad_800C14E0` agreed (0xdfff, `PAD_RIGHT`). The bytes come unchanged from ps2sdk's `padRead`
(`pad_ps2.c`; the input-script filter reads `host:`, absent on hardware), so the pad itself reported Right: in
digital mode many pads map the left stick onto the d-pad, and a stick resting off-centre holds a direction. MGS
never switches modes (it reads the pad directly), unlike SH1's game code, which calls `PadSetMainMode`. Now
`HalGame_Init` asks the HAL to put both pads in analog mode once ready (`Port_PadSetMainMode(port, 1, 0)`,
unlocked: the Analog button still toggles). PCSX2: boots as before. Not yet tried on the console.

**Codec audio artifacts (noted, not investigated).** The user heard artifacts in the dock's codec call. The log
has `SOUND ERROR:SPU OFF ENV ON(STR_TRACK_R=0)` / `(STR_TRACK_L=0)` from `sd_str.c`: the stream's two voices
found keyed off while their envelope still reads as on. Seen when a stream was stopped by a skip (358.97 s) and
also 7 s into a codec stream that wasn't skipped (649.08 s). Candidates: the HAL's SPU2 key-off/envelope readback
(`ENVX`) timing on hardware, or the stream's SPU writes falling behind. Check whether PCSX2 ever prints it.

## Step 6: Snake walks on his own: reproduced in PCSX2, not input (2026-10-28)

After the analog switch (console: pad ID 0x73, no buttons), the user reported Snake still moves with the stick
released (the crouching was gone), and that PCSX2 does the same. Sampled on the console: resting stick values
inside MGS's dead zone, holding right gives clean data (no button bits), and `GV_PadData[0]` reads status 0, dir
-1. So the pad layer tells the game nothing, and the movement comes from the game side.

`MGS_DEBUG_PLAYER=1` (link time) adds Snake's position and status and the pad's state to each HAL status line
(`HalGame_Status`, `port/src/hal_game.c`). PS1 reference: `tools/port/gdb/snake_ps1.py` drives DuckStation to the
dock's gameplay (presses written to mts's pad state each game loop, START through the briefing and codec) and
logs the same. First tries failed: presses at fixed loop numbers missed the title (the PS1's opening runs on its
own clock; now driven by the stage, via `NewLoader`); the idle log then started before the codec (status 0x20).

| | right after the codec | 1 s later | then |
|---|---|---|---|
| PS1 (DuckStation) | -5756 1104 -1298 | the same | still for 30 s |
| Port (PCSX2) | -5758 1130 -1294 | **-4203** 1132 -1304 | x steady, y bobbing 1074-1138, z -6/s |

The port moves Snake about 1550 units along x in one second with no input, then keeps sliding slowly. Too fast for
walking: more like collision or physics pushing him (as if inside geometry, or in a current). The console's
resting position (-4202 1074 -3046) fits the same slide, stopped by something. No `INCLUDE_ASM` or unwrapped
fixed addresses in `libhzd`, `game`, `libgv`, `libdg`. Next: per-loop comparison from the codec's end (Snake's
control state, the collision results of `libhzd`), to find the first loop where the port differs.

## Step 6: Snake ran on his own: the no-weapon action table (2026-10-28)

Narrowed in PCSX2 with `MGS_DEBUG_PLAYER` (now also passed to the game's files by `build_ps2.py`), from the
outside in:
1. `game/control.c` `GM_ActControl`, per stage for Snake's control: collision (`CheckCollide`, `CheckNear`,
   `CheckHeight`) barely moved him. His `step` was ~108 per loop along +x with a 17-loop wobble (a run cycle's
   root motion); collision only stopped him at a wall (x -4202).
2. `chara/snake/sna_init.c`, Snake's state function (`field_9B8_fn_anim`, looked up with `nm`): `sna_anim_idle`
   from loop 1907, no direction (`gSnaMoveDir` -1).
3. `game/motion.c` `NextKeyframe` (temporary print): the decoded root delta of the playing motion was (0, 108):
   the bitstream decode and the GTE rotation were right, the motion was a run.
4. `sna_anim_idle` takes its motion from `work->actpack->still->stand`, and `actpack` is
   `&weapon_actions_8009ED8C[GM_Weapon]`: with no weapon, `GM_Weapon` is -1. On the PS1, index -1 is
   `actions_no_weapon_8009ED70`, the `ACTPACK` (7 pointers, 0x1C bytes) linked right before the array. In the
   port they are 0x20 apart (the EE's GCC aligns the array), so [-1] began 4 bytes into the no-weapon table:
   `still` was its `move` table, and standing played a run motion.

Fixed under `MGS_PORT` at both sites: `GM_Weapon < 0 ? &actions_no_weapon_8009ED70 : &weapon_actions[...]`.
PCSX2: Snake stays at -5756 1104 -1298 after the codec, the PS1's position (`tools/port/gdb/snake_ps1.py`).
The other `[GM_Weapon]` indexings are guarded (`>= 0`) or use `+ 1`. The pattern (a negative index reaching the
variable linked before an array) may recur elsewhere in the decomp. Matching build: 80 OK, VR 2 OK.

## Step 6: TAS reference replay and trace; fixed test memory card (2026-10-29/30)

Plan: `docs/TAS Testing Plan.md` (TASVideos submission #5139, the all-bosses Integral run, 313,202 frames).

**Reference replay.** The movie needs BizHawk 1.11.4 (Octoshock): its `EmuHawk.exe` and `octoshock.dll` are
32-bit Windows binaries, so 32-bit Wine (`wine32:i386`) plus wine-mono 9.4.0 (GitHub) in a separate prefix
`~/emu/wine-bizhawk`; Microsoft's .NET wasn't needed. Failed first: the Direct3D display (Wine's shader compiler:
"Flatten if conditionals not implemented"; OpenGL works), the BIOS lookup (v1.0J `ps-10j.bin` is in BizHawk's
database but wasn't found in `Firmware/`; set explicitly), `--lua` (not in 1.11.4: the Lua console's own
auto-open setting and the recent-script auto-load do it), `pcall` around `emu.frameadvance` (Lua 5.1 can't yield
across it), `client.speedmode(6400)` (invalid in 1.11.4). Discs: cue/bin from the CHDs (`chdman extractcd`), both
listed in an XML bundle. `tools/port/tas/run_bizhawk.sh [script.lua]` runs it with no clicks and a stall watchdog.
The whole movie plays in sync: 118 stage visits, disc change at frame 181,800, credits from 290,400.

**Trace.** `tools/port/tas/trace.lua`: one line per game loop (`GV_Time` change) with the pads the game read,
clock, `rand` seed (`0x800C1530`), stage, position, `linkvarbuf`. Two runs identical. Full trace running.

**The movie's memory card.** The trace shows the save doesn't set game state: Extreme is chosen on the New Game
menu (frame 1,582, `GM_GameLevel` 3). The title (`onoda/open/open.c`) only reads the card's file names: card 1
holds `BISLPM-86247G:E0pBAA` (clear flag 2: `has_clear_data`, rank 2, Extreme unlocked). So no memory poking:
the HAL gained fixed test cards (`src/ps2/memcard_fixed.c`, `SH_PORT_MC_FIXED`, in place of `memcard_ps2.c`):
both PS1 slots hold cards from an image linked in, writes stay in EE memory. MGS: `MGS_MC_IMAGE=<file>
python3 build/link_ps2.py` (the movie's `MovieSaveRam.bin`, both cards back to back). PCSX2: the title prints
`clear data exists BISLPM-86247G:E0pBAA`, `This Is Rank 2`, `demo_rank = 2`. Matching build: 80 OK.

## Step 6: TAS replay in the port (2026-10-30)

`port/src/tas_replay.c` with hooks in `libgv/pad.c`, `libgv/gvd.c`, `mts/mts_pad.c`, `game/loader.c` and
`capture_ps2.c`'s stream hooks; `tools/port/tas/trace_to_pads.py` and `compare_trace.py`; the HAL's
`Hal_RandSeed` (its PS1 `rand`'s state). Details and the build line in `docs/TAS Testing Plan.md`, Phase 3.

What was tried: replaying the raw pad (`pad_800C14E0`) for `GV_UpdatePadSystem`: the trace samples it at frame
end, and the stick bytes the game copied matched the previous line's only 99.7% of the time, so the port
writes the reference's `GV_PadData` itself. Keying everything by `GV_Time` from boot: the title arrives at loop
36 here, 146 on the PS1 (its loads loop longer), and loads differ both ways, so at each load end the port takes the
PS1's `GV_Time`, `GV_Clock` and `GV_PassageTime`. Holding the load end until the PS1's loop: didn't help where
the port's load was the slower one. An execute callback on `FS_StreamGetTick` in BizHawk: registers, never
fires (Octoshock 1.11.4); the tick is computed from `mts_time` and `stream.c`'s statics (read from
`FS_StreamSoundMode`'s code). `GM_CONFIG_VIBRATION_OFF` differed: `gamed.c` sets it from the pad's vibration type,
so the raw pads and `pad_state_800C14F0` are replayed too.

PCSX2 (dock): no TLB misses; identical to the PS1 from New Game to loop 1015 except the stubbed streams'
effects. First gameplay difference: loop 1016, Snake's first running steps after the ladder.

**Saved in the repo** (2026-10-30): `tas/` holds the movie and the full reference trace (163,839 loops, made with
the final `trace.lua`; `xz` 105 MB to 1.5 MB) and a README on remaking it and replaying it; the tools read the
`.xz` directly. The unattended full run ended correctly: `OK`, last line frame 313,202 in `roll`, BizHawk closed
itself. Matching build: 80 OK, VR 2 OK; the port links with and without the TAS options; SH1 links with the HAL
changes.

## Step 6: TAS harness fixes; 16 MB limit; Snake turns a loop early (2026-10-30)

**Sample points.** A loop runs `gvd.c`'s `Act` (`GV_Time`, clock, passage time), `dgd.c`'s wait for the vertical
blank and pad update, then the actors; BizHawk's line N is taken during the wait. Snake's position diverging at
loop 1016 first looked like the trace's sampling, so the pads were tried both ways: with line N's pads the title
goes to New Game a loop late; with line N+1's (kept) it matches. The port's trace samples at the end of
`gvd.c`'s `Act`, once per loop.

**TLB misses at boot from a bigger ELF.** With the full replay tables linked in (5.6 MB), `DrawOTagImpl` read
`0x20257`/`0x43170`: `.bss` (the ordering tables, `DG_Chanls`) had passed 16 MB, and the HAL keeps ordering-table
links as 24-bit PS1 addresses. Small tables: no misses. Tried: a `.tasdata` section after `.bss` (crt0 zeroes
`_fbss`..`_end` and starts the heap at `_end`). Kept: the tables are read from `host:` into the heap at startup
(`Port_TasInit`), and `port/linkfile` asserts `_end_bss <= 0x1000000`.

**Snake's turn.** `trace_debug.lua` (stops at frame 3,300) and the port's trace add `GM_PlayerStatus` and Snake's
`CONTROL`. Loop 1012 (0:00:48.50 in the movie): same `GV_PadData` (dir 2951) and status, but the port's
`CONTROL.turn` takes 2951 a loop before the PS1's; rotation and position follow a loop early. `compare_trace.py`
prints movie timestamps. Matching build: 80 OK, VR 2 OK.

**Snake's turn, continued** (2026-10-30): Snake's state function and turn countdown (`trace_debug.lua`: his work
from `0x9B0`, the function pointer resolved through each side's symbols) are identical to loop 1011; the port's
starts the turn a loop earlier because it was given loop 1011's pads with the new direction. Whether the
reference's pads for a loop are on line N or N+1 differs between the dock and the title. Tried: a rule from the
game task's wait (`mts_tasks_800C0C30[3].intr`, now field 18): dock fixed to loop 1040, intro's loading loops
broken; reverted. BizHawk 1.11.4's execute and write callbacks don't fire for PSX. Next: DuckStation's GDB.

**Control run in PCSX-Redux** (2026-10-30): `tools/port/tas/redux_replay.lua` runs the PS1 game under the port's
harness (execute breakpoints at the same hooks, the same tables). The real PS1 code shows the same loop-1012 turn,
so that's the harness; the port against it: Snake identical through the dock. Port differences left: the intro's
demo stream (`DG_UnDrawFrameCount` 7 loops early), the seed at 809, `GM_GameStatus` bit `0x40` at loop 1,164.

**Pad timing settled** (2026-10-30): with `GV_LastTickCount` in the trace every BizHawk line is taken before its
loop's pad update. Snake's early turn: at the codec's end a loop updates the pads twice (`dgd.c` with
`STATE_PADRELEASE`, then the codec script's pad command), and the harness wrote the final recorded `GV_PadData` at
both. Now it rebuilds the raw pads at `GV_UpdatePadSystem`'s entry and the game computes `GV_PadData` (identical
to BizHawk's in the control run). Snake matches to loop 1,078 in both runs. Matching build: 80 OK, VR 2 OK.

## Step 7: TAS stream timing (2026-10-30)

The intro's demo packet came 10 loops early in the Redux control run (7 in the port). The stream start gate keyed
on `STATE_VOX_STREAM`, which `strctrl.c` sets when its actor is made (loop 489), while the PS1's stream clock started
at 512. The tables now count the PS1's stream starts and a start waits until ours are behind. The tick table took
the stream clock after the loop's last call, which is wrong in the audio packet's loop (`FS_StreamSoundMode` resets
it) and a stream's last loop; both now use the clock before the loop. A new trace field (stream data in from the
disc, `fs_stream_bottom`) holds Redux's `FS_StreamGetData` to the PS1's disc speed. Two mistakes cost runs: the
executable's base (0x8000F800, not 0x7FFFF800) and setting a register in a load delay slot. Field 20 (CD file
read left) was tried as a gate for the codec's radio data load and made things worse (opt-in, documented).

The full BizHawk reference was rerun with fields 18-20. In PCSX2: the intro's stream matches; Snake matches to loop
1,781. Left: the intro codec's call state a few loops early (seed, resynced at 921) and `STATE_CUT_IN` at 1,164.
Matching build: 80 OK, VR 2 OK.

## Step 8: TAS desyncs to 2:35 (2026-10-30)

With `run_port.py` stopping at the first desync, four were fixed in turn: the rand seed at loop 930 (0:00:45.76),
not resynced at the start of the s00a load, which skips `loader.c`; the play time (`gTotalFrameTime`, new trace
field 21, synced at load ends); `STATE_CUT_IN` at 1,164 (0:00:53.57), a port bug: `camera.c` reads
`GM_CameraList[-1]` with no camera, which on the PS1 is a zero half-word of the struct before it; the sticks at
2,462 (0:01:36.88), skipped by the pad rebuild while the d-pad was held in analog mode. Each fix was checked in the
Redux control run. Tried and dropped: setting the seed at `NewLoader` (this load doesn't use it). The full
reference was rerun with field 21. In PCSX2 the replay is now in sync to loop 4,221 (0:02:35.57), Snake's position
off by one there. Matching build: 80 OK, VR 2 OK.

## Step 9: wall knock line check, desync screenshots (2026-10-30)

Snake's position at loop 4,221 (0:02:35.57) was traced back in four steps, each by logging the same values in the
port and the Redux control run (which matched the PS1 there): Snake's punch at 4,219 homes on a guard
(`GM_GetHomingTarget2`) the port had elsewhere; that guard's path split at 3,997 (0:02:28.10) when the PS1's heard a
noise at 3,994; the noise was Snake's wall knock at 3,988, whose `afterse.c` actor the port never made because its
wall check found no wall. Cause, a port bug: `sna_8004F544` passes `&vec1` to `sna_line_check`, which reads the
line's end as `line[1]`, i.e. `vec2`, next to `vec1` on PSY-Q's stack but not GCC's. Under `MGS_PORT` the pair is
an array; three more `sna_line_check` callers in `snake.c` and `sna_init.c` had the same pattern and were changed
too.

New: at a desync `run_port.py` reruns the port to that loop with its frame dumped (`MGS_TAS_SHOT`) while the Redux
control run saves its screen there (`TAS_SHOT`), and writes `tas/shots/loop_<T>.png` (PS1 | port | pixels differing
by more than 24) with the desync's text. A screenshot is only judged by such checks: a first look at loop 4,221's
called the missing figure Snake; it was the guard.

In PCSX2 the replay is now in sync to loop 5,109. At 5,110 (0:03:05.37) `GV_PadData`'s release bits (0x4010) are
missing as `GM_GameStatus` changes; the Redux control run shows the same, so it's the harness's pad rebuild. Its
screenshot also differs over most of the top half (not looked into yet). Matching build: 80 OK, VR 2 OK.

## Step 10: pad release under STATE_PADRELEASE (2026-10-30)

Loop 5,110 (0:03:05.37), a harness problem (the Redux control run showed it too): a script's `pad -r`
(`script.c` `PadCmd`) sets `STATE_PADRELEASE` and updates the pads a second time in the loop, and the PS1 reports
the held buttons' release (0x4010). The tables rebuilt the controller from `GV_PadData[2]/[3]`, which the flag had
already zeroed. `trace_to_pads.py` now takes the buttons from mts's raw pads (trace field 8) where the game zeroed
them (`STATE_PADRELEASE` or `DG_UnDrawFrameCount`) and the recorded ones are 0. Tried first: the same for
`STATE_PADMASK` and without the zero check; it broke loop 5,002 (0:03:01.70), where the flag came after the loop's
update. Redux control run: matches to 5,300. PCSX2: in sync to loop 5,750; at 5,751 (0:03:21.53, `d01a`)
`DG_UnDrawFrameCount` is 3 against the PS1's 0x7FFF00EC (screenshot `tas/shots/loop_5751.png`).

## Step 11: stream clock after FS_StreamSoundMode (2026-10-30)

Loop 5,751 (0:03:21.53, `d01a`), the harness (the Redux control run too): after the audio packet `strctrl.c` calls
`FS_StreamSoundMode` (clock -1, 1) and asks for the tick again in the same loop (`goto loop_case3`); the PS1 got
-1, so the demo packet (`DG_UnDrawFrameCount = 3`) waited two loops, while the harness returned the loop's tick to
every call. Now, after `FS_StreamSoundMode` in a loop, the tick is -1 (port: `Port_TasSoundMode`; Redux: a
breakpoint at 0x80024404). Its screenshot was black on both. Redux control run: matches to 6,500. PCSX2: in sync
to loop 5,808; at 5,809 (0:03:24.39) the rand seed differs. Matching build: 80 OK, VR 2 OK.

## Step 12: faster TAS iterations (2026-10-31)

Loop 5,809 (0:03:24.39) first: gating the codec's file poll (`radiomes.c`) on the PS1's bytes left didn't help.
The port's codec read runs at loops 5,775 to 5,782 and the PS1's at 5,795 to 5,816, so the port requests the file
early (TAS plan). Reverted.

Then the time per iteration, measured to that desync: link 34 s, PCSX2 replay 44 s (4.4x real time), and for the
screenshots the Redux control run, 253 s. Changes:
- `build_ps2.compile_cached`: a gcc command is skipped when its object is newer than the source and every header
  (gcc's `.d`) and was made by the same command line (`.cmd`). The overlays, HAL and `port/src` now compile in
  parallel through it. A link with nothing changed: 11 s, 8 of them the 1.4 GB disc image (`mkiso.py`, shared
  with SH1, left as it is).
- The screenshot loop is read at startup from `host:tas_shot.txt` (`run_port.py --shot`), not a `-DMGS_TAS_SHOT`
  build, so the rerun at a desync doesn't link again. Same desync, byte-identical screenshot.
- The control run's screens are cached in `obj_ps2/shots/cache/`, keyed by the loop, the tables and
  `redux_replay.lua`. A run to the 5,809 desync with screenshots: 309 s, then 96 s with the cache.
- Tried: Redux's dynarec instead of `-interpreter`. Its breakpoints never fire (empty trace), so no.
Matching build: 80 OK, VR 2 OK.

## Step 13: the PS1 drive's pace for file reads (2026-10-31)

Loop 5,809 (0:03:24.39): the codec's face read is waited for by the call's `rand()`. The Redux control run showed
`fs_stream_task_state` already 0, so it's the PS1's CD drive: the face read drains at 2.5 sectors a vertical blank
and the call's 2-sector `RADIO.DAT` read before it takes 42 vertical blanks after the demo stream (a long seek).
The port's reads are instant. Rather than gating each read on the PS1's numbers, TAS builds now pace file reads
(those without a callback) in `port/src/cdbios_ps2.c`: the read isn't reported done before its sectors would have
come in at the PS1's rate, plus a seek of 1 + 0.075 * sqrt(distance) vertical blanks, fitted to the trace's codec
reads with a small calibration log (about 3 vertical blanks for 1,415 sectors, 29 for 120,341).
Tried and failed, all at loop 917 (0:00:44.89, the intro call running late): pacing streams and stage loads too
(streams already follow the PS1's tick table, loads end at its loop), and a fixed 10-vertical-blank seek. What
counts: the harness waits for a port that's early (stream starts, load ends), not one that's late, so the model
errs short. Also: the port trace has the file read's bytes left (field 20; not compared), and lines are left out
while the port still loads past the PS1's load end. PCSX2: in sync to loop 6,276; at 6,277 (0:03:37.57, `s01a`) the
rand seed differs. Matching build: 80 OK, VR 2 OK.

## Step 14: seeks fitted to the PS1, stream reads at the PS1's pace (2026-10-31)

Loop 6,277 (0:03:37.57): the codec's states in the PS1, logged by a throwaway BizHawk Lua (BizHawk reaches loop 6,000
in about 3 minutes), against the port's from a debug print: one loop off at the face read's end shifts the call's
`rand()` draws (a 16-loop countdown to state 5, two draws every 4th loop). The Redux control run doesn't match the
PS1 here, so it's no reference for drive timing. The drive model now charges a read only for the sectors it wants,
and seeks follow a table over sqrt(distance) fitted to the three calls (intro, `d01a`, `s01a`); a chunk that goes
on from the last one is timed from where that was due. Loop 6,497 (0:03:46.01): the second `s01a` call's
`RADIO.DAT` seek was near zero, because the port's modelled head never moved to the held voice stream; held stream
reads now move it. Stream reads: a stream's first read waits for the PS1's first data (the codec's voice at 5,827:
5,950), and its sectors reach the game only as far as the PS1's had by the loop's end. PCSX2: in sync to loop
6,662; at 6,663 (0:03:52.10) a cutscene's packet is in a loop early (sub-loop timing; three variants tried, TAS
plan). Matching build: 80 OK, VR 2 OK.

## Step 15: stream data per vertical blank, raw pads after the pad update (2026-10-31)

Loop 6,663 (0:03:52.10): a per-frame BizHawk log (throwaway Lua reading the PS1's memory each frame) showed the
drive's 2.5 sectors a vertical blank and that a loop's logic uses what had come in at its start; the stream gate
now follows that within the loop. Loop 6,667: `pad_demo.c` reads the raw pad for the cutscene skip after the pad
update, and the port's raw pads then held the next trace line's buttons (`Port_TasPads`); they're put back to the
PS1's at the end of `GV_UpdatePadSystem`. PCSX2: in sync to loop 6,732, then a crash in `DG_TransChanl` (corrupt
sp; TAS plan). Matching build: 80 OK, VR 2 OK.

## Step 16: the crash after loop 6,732, a dropped model initializer (2026-10-31)

The crash in `DG_TransChanl` (corrupt `s0`/`s7`/`sp`, then PCSX2's "Jump to unaligned address") came from
`takabe/lit_mdl.c`: its static `DG_DEF` initializes the zero-length `models[]`, which modern GCC drops with a
warning, so the actor's copy of header and model read the next globals as a model of 2.5 million vertices.
Transforming it wrote through the emulated scratchpad onto the game thread's stack. Ruled out on the way: a
scratchpad overrun by a real model (largest 126 vertices, the buffer's size), bad draw queue entries, task stack
overflows (32 KB mts stacks, 64 KB EE thread stacks with marks). Found by printing every object as it's
transformed, then logging `DG_MakeObjs` calls whose model had an impossible vertex count with their caller.
No other source file has that warning. PCSX2: in sync to loop 7,596; at 7,597 (0:04:21.14, `s02a`) the rand seed
differs. Matching build: 80 OK, VR 2 OK.

## Step 17: file reads follow the trace; pads at the elevator and at load ends (2026-10-31)

Loop 7,597: a codec face read that the PS1 started 19 vertical blanks late for a short seek; rather than a better
drive model, file reads now follow the PS1's recorded progress (the read of the same size, matched in time.bin),
as streams do. Loop 9,253: BizHawk screenshot and memory reads (the elevator panel's actor found by its filename
string) led to the raw pads: where the game zeroed the pads, the harness rebuilt them from the next line's raw
pads instead of the loop's own. Loop 9,633: at a load's end the port's pads were those of its own (much earlier)
loop number; now loads.bin carries the PS1's GV_PadData at each load end, and the loop after the loader's end
reads the PS1's last load loop's pads. BizHawk's trace_debug.lua (Snake's work) showed the anim frame a loop
ahead. PCSX2: in sync to loop 11,443; at 11,444 (0:06:19.70, `s03d`) the rand seed differs.
Matching build: 80 OK, VR 2 OK.

## Step 18: loop 11,444 is a missing overlay, not a desync (2026-10-31)

The PS1's actor list at loop 11,445 (read from its memory in BizHawk) has the `s03d` stage's actors; the port's
doesn't, because `s03d` is left out of the port for its 21 undecompiled guard functions. Decompiling them is the
next job (TAS plan). Two helpers for it: `tools/port/match_asm_funcs.py` (which decompiled function an
INCLUDE_ASM one resembles, by call sequence) and `tools/port/fdiff.py` (instruction diff of one function against
the matching binary).

## Step 19: s03d's guard functions, the 11 with counterparts (2026-10-31)

Eleven of `s03d`'s 21 INCLUDE_ASM functions decompiled to matching C, each from its closest decompiled counterpart
(`tools/port/match_asm_funcs.py`) with the fields mapped from the assembly (`tools/port/disasm_s.py`) and checked
instruction by instruction (`tools/port/fdiff.py`) and with the matching build: `s03d_800CF194`, `800CEE3C`,
`800CF68C`, `800CFB04`, `800D46F8` (zakocom.c), `800CE12C`, `800CDF94`, `800CE720`, `800CE318`, `800CCE3C`,
`800D09D8`. What it took beyond the field mapping: jump tables move out of the rodata files (`overlay2.c`,
zakocom.c's own block, the constants after them moved below the function so the order holds); inline helpers
(`SetAction`, `SetMode`, `SetMode2`, `SetModeFields`) for the PS1's instruction scheduling; zako11a's empty
`for (i = 0; i < 0; i++)` loop in the init function for its block layout; `PARAM`'s 0xB16 is the faint, not
`max_life`; new fields `field_AF8`, `field_B98`. Ten remain (no close counterpart), then `s03d` goes into the
port. Matching build: 80 OK, VR 2 OK.

## Step 20: s03d complete and in the port (2026-10-31)

The rest of s03d's guard code decompiled (matching): the damage check, reset, action update, grenade, the five
small functions of `800D0C90`, GetResources and the guard's constructor, and zakocom.c's sequence, setup and
constructor. Two only for the port (register choice differs, `#ifdef MGS_PORT`, the matching build keeps the
asm): the senses (`800D1054` + 3) and `800D14AC`. Then the stage table and `overlay2.c`'s pointers by symbol, and
`s03d` links into the port. New in the decompiling: jump tables inside a rodata file move with the constants after
them; GCC 2.x reverses ascending loops (so the source counts up); `Work` is 0xBA4 bytes. The replay then showed
TLB misses: chafgrnd.c's chaff tiles have a NULL rect, read from PS1 RAM at 0 (3, 0, read in BizHawk); the port
now uses those values. PCSX2: in sync to loop 12,101 (0:06:42.1); at 12,102 `GM_GameStatus` 0x20 differs.
Matching build: 80 OK, VR 2 OK.

## Step 21: stream ends on the PS1's loop, and overlay data laid out as the PS1's (2026-10-31)

- **Loop 12,102 (0:06:42.12), `STATE_VOX_STREAM`:** the port's voice stream ended a loop early. The end waits for
  the SPU to play the last of the voice (`sd_str.c`'s interrupts), and the port's IOP does that at its own pace.
  Now strctrl.c's `Act2` holds the actor's destroy (its `Die` clears the bit) while the PS1's record shows the bit
  for the next loop (`Port_TasStreamMayEnd`; `Die` runs a loop after `GV_DestroyActor`). Tried first: holding
  `Act`'s end, which broke loop 519 (the PS1 ends the demo at 518 and clears the bit at 520), and reading this
  loop's record (`Die` ran a loop late, the load at 521 late). A bit still set 8 loops on is the next stream's (the
  demo at 11,482 is followed by another); the hold is bounded to that.
- **Crash at loop 12,652 (0:07:00.75):** the guards' `GM_InitObject` hashed "ippa" plus padding: their model
  names are strings split into 4-byte char arrays, which GCC for the EE aligns to 8 bytes. Found by logging
  `GM_ConfigObjectModel`'s missing models (hash 0x4e97, 0x9235) with their caller (`s03d_800CCE3C`), and `nm`.
  Then TLB misses in zakocom.c: `ZakoComMgr` is `s03d_dword_800DC310` and the words after it, which the port
  had as common symbols in the linker's order. `overlay3.c`'s words now have their own `.bss` section under
  `MGS_PORT`. Tried first: `-fno-common` for every overlay file, which hung the game at loop 11,520: a common
  symbol stays global past `overlays_ps2.py`'s `--keep-global-symbol`, so an overlay's tentative definition of a
  shared variable is the main executable's; out of common it became a private copy.
- **Loop 12,758 (0:07:05.19), rand seed:** one `GV_RandU` fewer (`--wrap=rand` logging the callers, then
  `GV_RandU`/`GV_RandS`'s). Comparing the guards' state per loop (`tools/port/tas/zako_log.lua` in BizHawk against
  a `printf` in the port) showed the third guard falling at loop 12,696 (0:07:02.61): the PS1 played action 34,
  the port 0. `((short *)&s03d_dword_800C39E0)[36]` reads a table past its first word, and the port had gaps in
  it: explicit zeros go to `.bss`, and arrays were 8-aligned. Now overlay files compile with
  `-fno-zero-initialized-in-bss` (`build_ps2.py`), and their initialized arrays carry `PS1_ALIGN(n)`
  (`source/include/ps1align.h`, empty in the matching build: 2 for short, 4 for int and char arrays, as the PS1's
  GCC; `STR_PIECE` for the split strings). `nm` then shows `s03d`'s data with no gaps.
- **Open:** an intermittent hang at loop 11,520 (0:06:22.25, `s03d`, frame 8,812), in 3 of about 12 runs, all
  after the split-string fix (the guards' first loops). The HAL's hang watch now writes the interrupted PC by SIO
  once a second while it sees a hang (`libetc_ps2.c`); no hang has come since it was added. Common symbols from
  shared actor files (`enemy/asiato.c`, `takabe/findtrap.c`, `okajima/blur.c`, ...) still have the linker's order.

PCSX2: in sync to loop 12,770 (0:07:05.59), where the run was stopped (not a desync). Matching build: 80 OK, VR 2 OK.

## Step 22: console testing, the scope crash and a list of issues (2026-11-01)

The user played on real hardware while the log (`~/ps2serve/ps2.log`) was watched for crashes.

- **Yellow screen in the scope:** the HAL's hang watch colour for stopped threads. The crash was in
  `DrawMovingBarGraph`: PS1 `nextPrim` ORs in 0x80000000, a KSEG address that faults in EE user mode.
  `source/equip/scope.c` and `source/menu/debug.c` now redefine `nextPrim` under `MGS_PORT` to return the tag's
  address as it stands. The user confirmed the fix on the console. The first log watcher missed this crash.
- **HAL:** the hang watch prints the interrupted EPC by SIO (`libetc_ps2.c`, in `../psx-to-ps2-HAL`, uncommitted).
- **Memory card hang, now top of the to-do list:** saving in game stays on the check for a memory card. A PS2 card
  with a Silent Hill save is in the slot, and MGS1 has to create its own save. The log ends with task 7's start,
  `REQUEST 100000A`, `RESULT 0`. Not investigated.
- **Noted, not investigated:** minor texture seams, including on the opening credits and the life bar (suspect, not
  tested: textured quad UVs have no half-texel offset, `gpu_gs.c:1441`); codec audio popping; the slow wading at the
  Dock, to run at 60 FPS with the same heavy feel (`docs/60 FPS update.md`).

The last 30-minute log watch saw no crash or hang. The TAS was not run in this step: still in sync to loop 12,770
(0:07:05.59). Matching build with these changes: 80 OK, VR 2 OK.

## Step 23: memory card saving, first fixes (2026-11-02)

The log ended at `RESULT 0`, the next line of the save task being `memcard_check`.

- **Check hang:** `PortMc_InfoPoll` answers only on `s_MainThread` (the task that called `InitCARD`), and MGS saves
  from its memory card task, so `_card_info`'s event never came. `PortMc_InfoWait` now returns the state itself.
- **Write hang, found by reading the code:** `memcard_status()` counts down by a `HwCARD` event per 128-byte frame,
  which the HAL didn't send. New setting `HAL_GAME_CARD_FRAME_EVENTS` (MGS only) sends them on asynchronous
  transfers, and `EvSpERROR` when a write fails.

Built, but not run in PCSX2 or on console: the deploy found the PS2 not answering. Next: a first save and load on
real hardware. PS1 saves copied to the card come later. Neutrino reset hangs went on the to-do list (medium).

## Step 24: the seed check, late reads and lip sync's clock (2026-11-02)

From SH1's replay system (`replays.md`): the seed is compared before any overwrite, and a late file read waits at
the loop's end (`file_wait`; the first version also waited on a stream's endless read and stalled at loop 5,471).
`FS_StreamGetData` stops at the PS1's `fs_stream_bottom` (`Port_TasStreamBottom`). These last two moved no desync.

Rand seed at loop 12,835 (0:07:07.76): guards matched in every logged field, and counting draws between seeds showed
an occasional draw a loop early, Snake's lip sync. `jimctrl.c` reads the sound counter directly, so the port's IOP
paced it. `Port_TasStrCounter` derives it from the PS1's tick. The first rounding came out 1 low on many loops, which
gave loop 12,879 (0:07:09.26); `str_tick_count` logged in BizHawk gave the exact inverse.

PCSX2: in sync to loop 13,005, desync at 13,006 (0:07:13.55). Matching build: 80 OK, VR 2 OK.

## Step 25: the disc timeline, first slice (2026-11-02)

The stream patches kept breaking at chained streams, so the PS1's stream state is now recorded per loop:
`tools/port/tas/timeline.lua` (StrctrlWork's act and state, stream data, CD bytes left, sound counter), then
`timeline_to_bin.py` to `tas_timeline.bin`. `Port_TasStreamMayEnd` lets the port's Nth stream end once the PS1's Nth
has (recorded to loop 14,000; the old logic beyond). Tried first: comparing by loop, where a late port never ended its
stream; releasing at the tick's reset, which broke loop 11,483. The old patches stay until the timeline proves better.

PCSX2: desync at loop 13,006 (0:07:13.55), unchanged, now with the chained stream's read 2 loops late, not 7.

The sound counter once a loop in BizHawk isn't the value `jimctrl.c` read (recorded values gave 12,835 or 12,879), and
Redux's control run desyncs at loop 6,669 and is too slow to use here. `jimctrl.c`'s `field_30` ends its loop at the
counter >> 2, so the timeline samples that: loop 13,006 (0:07:13.55) fixed. Next: `STATE_CUT_IN` at 13,015 (0:07:13.88).

## Step 26: the stream's play end from the timeline (2026-11-02)

The full-movie timeline recording finished (293,407 loops by `GV_Time`, against 163,838 in the reference trace; the
difference isn't explained yet, and 8 small gaps in `t` are zeroed in `timeline.bin`).

The desync at loop 13,015 (0:07:13.88), `STATE_CUT_IN` a loop late, looked like a camera trigger. Recording the PS1's
`GM_event_camera_flag` and Snake's position ruled that out, and logging `delay.c` and `GCL_ExecProc` traced the script
to `s03d_800D4EAC` in `zakocom.c`. Lip sync and delays were both wrong leads. The guards' cutscene waits for the stream
to end (case 4), then counts 60 loops (case 5). The PS1's stream reached `Act2` in loop 12,951, the port's in 12,952,
with the read already done.

`Port_TasStreamPlayEnd` (TAS only) ends the port's Nth stream's play when the timeline shows the PS1's did, if no read
is running. Normal play keeps the original test; the stream patches stay. In sync to loop 14,030 (0:07:50.07), where
`GV_Clock` differs. Tried in the emulator only, not on the console.

`GV_Clock` at 14,030 first looked like `dgd.c`'s frame skip, but `STATE_NOSLOW` isn't set there. It was a sampling
artefact, corrected in `compare_trace.py`. In sync to loop 15,061 (0:08:18.40). Milestones: `docs/TAS Progress.md`.

The TLB misses at loop 15,0xx were `s03d_800D47BC` sorting through a removed guard's NULL entry; the PS1's RAM at 0xB90
is 0 (BizHawk). The desync at 15,061 was a map trap firing a loop late because `pads.bin` lost a button press under
`STATE_PADRELEASE`. Checking for an all-ones status changed nothing (a misread of the record); using the `press` field
with line t+1's raw pads fixed it. In sync to loop 15,114 (0:08:20.18), where the play time seconds differ.

The play time at 15,114 differed only as bookkeeping: `gTotalFrameTime` now follows the recording each loop. In sync to loop 17,042 (0:09:20.38), a seed difference in `s04b`.

The seed at 17,042 was lip sync at a clip's end: the PS1's sound ends during a loop, so jimctrl.c reads the old counter there and -1 in the next. `timeline.bin` now carries the end. In sync to the FMV at 17,561, which hangs on HAL stubs. Ponytail rules added to CLAUDE.md.

The hang at 17,561 was the movie player, which the TAS skips with a button. `movie.c` now skips movies in the port (real playback stays on the Planning Doc), and in TAS replays ends on the PS1's loop. In sync to loop 18,261 (0:09:55.34).

At 18,261 the port entered the codec's call state just before a multiple-of-4 loop and the PS1 just after, so the port drew twice more. The draws only animate the signal bars, so `Port_TasCodecDraw` follows the PS1's seed (a marked shortcut). In sync to loop 20,842 (0:11:11.65).

At 20,842 the stage binary `s05a` wasn't linked in. Its 76 literal pointers and stage table are now by symbol (byte-exact in the matching build), and it links. In sync to loop 20,980 (0:11:16.64).

The seed at 20,980 follows a reload: the port lacks 5 PS1 draws in loop 20,979, and tagging every `rand()` and `GV_Rand` found no port caller. A one-loop resync at 20,980 stands in, marked as a shortcut. A resync after every load, and separately a HAL `rand` log, both hung near 6,668 repeatably; clean builds do not. That hang is unexplained. In sync to loop 21,126 (0:11:21.60).

At 21,126 the port makes a burst of 5 draws two loops before the PS1, the same size as the 20,979 mystery. `GV_Rand`, the
raw `rand()` sites tagged so far and `snowarea.c` are ruled out; the function list with many `rand` calls is the next lead.

The 5-draw bursts were the tank tread dust. A small HAL ring of `rand` return addresses named the caller without the hang. The right tread reads `svect3.vy` unset; PS1 disassembly puts that slot on `s05a_800DA940`'s `verts[9].vy`. The port now saves that value, and the 20,980 resync is removed. In sync to loop 22,669 (0:12:12.48).

The TLB miss at s05a_800E00EC reads RAM at 8 and 12 (8, 0x340, 0, 0). The pad difference at 22,669: the codec end updates the pads twice, and the first took the release; `Port_TasPadsDone` restores the recorded one. In sync to loop 23,572 (0:12:39.38).

`s07a` wasn't linked in; its 7 literal pointers are now symbols. In sync to loop 24,704 (0:13:15.64).

The seed at 24,704 was the codec static a loop early, gated like the signal bars. `s05a_800E1F0C` read 0xE5C through NULL; the PS1 value is 0x8C960024. In sync to loop 27,191 (0:14:34.37). `s08b` is still a stub overlay.

Emulator windows now run on an invisible Xvfb display by default (`tools/port/offscreen`); `--show` or `MGS_SHOW=1` shows them.

`s08b` (122 INCLUDE_ASM stubs, 119 in ninja.c) isn't hand-decompiled. `tools/port/mips2c.py` turns each stub into exact-behaviour C for the port only: PS1 registers and stack frame, addresses mapped to symbols through the link map, jump tables read from the PS1 binary. Its 260 literals are symbols or (unused jump tables) decimals. The matching build is unchanged. Bugs on the way: a `lui` in a branch's delay slot, and functions split across two stubs. `link_ps2.py` now picks the Integral discs: other game versions in `ps1-original/` had been extracted instead (19:26), which showed as `illegal DISK`. The freeze at loop 27,185 is layout-sensitive like the 6,668 hang: all threads idle, gone with a one-word build change.

More `mips2c.py` fixes: stubs that hold several functions are split at each entry point (after a `jr ra`, at a frame setup or an address the code takes), so callbacks such as the camera's are real functions; a `lui` in a branch's delay slot carries to the target, and an address seen once in a function is reused on other paths. `recomp.h` records the translated functions last entered (`Port_RecompLast`), which also happens to keep the layout clear of the deadlock. The Ninja's constructor runs, but its `Act` doesn't yet.

mips2c.py's jump tables took the offset from the `lw` instead of the `addiu`, so every switch fell through; with that fixed the Ninja's state machine matches the PS1 to 27,232. The post-load deadlock struck again at 24,537 (`s08a`); 64 bytes of code padding in `tas_replay.c` (a marked shortcut) moves past it. TLB misses (NULL+0/2/4) in `DG_GetLightMatrix` are still open.

At 27,232 the port read the voice counter one higher than the PS1 on a loop the PS1's field_30 held; `Port_TasStrCounter` now holds the last value when a move follows. In sync to loop 29,057 (0:15:36.67).

At 29,057 the hold carried the previous stream's large counter into a new one, ending its mouth data at once; it is now bounded by the estimate. The Ninja fight then plays through: in sync to loop 35,095 (0:18:39.13). The intermittent 11,520 hang showed up again with a logging build: the same post-load deadlock.

## Step 27: the post-load deadlock is a lock held across a thread switch (2026-11-03)

With the 64-byte padding removed, the hang came back (loop 11,520, 0:06:24, then 26,136, 0:13:59 with another build). A one-shot dump from `hang_watch` (each PS1 thread's park state and real EE thread status, mts's task table, return addresses found on each thread's stack) showed it: mts's active task was 1 (`SOUND_INT`, TCB 6), the HAL's running thread, but its EE thread was waiting on semaphore 1; the game thread (TCB 3) and TCB 2 were suspended by interrupt switches. Semaphore 1 isn't one of the HAL's (the SPU lock is 33): ps2sdk creates it before `main`, for newlib. TCB 6's stack: `IntSdMain → printf → _vfprintf_r → __sbprintf → _malloc_r → __retarget_lock_acquire_recursive`; the game thread's: inside `_vfprintf_r`/`_malloc_r` from GCL code. A vertical blank switch had suspended the game thread holding the C library's lock, and the sound task's `printf` waited for it for good. The PS1 has no locks to hold across a switch; the layout only moved the timing, and logging builds widened the window.

Fix (HAL `thread_ps2.c`): while the current PS1 thread holds a lock, an interrupt switch waits (`s_SwitchPending`) and is made at the release with a `ChangeTh`, before the thread runs game code again. Counted before the acquire. The C library's locks are counted through `--wrap=__retarget_lock_{acquire,release}[_recursive]` (`build/link_ps2.py`, and SH1's `port_link.py`, which links the same HAL); the SPU lock (`spu_ps2.c`), which GAME and the sound tasks share in MGS, the same way. Try-acquires aren't counted (newlib only uses them in `ftrylockfile`); the count can't go below 0.

Checked: no padding, in sync to the known desync at 35,095 (0:18:39.13); a stress build printing in every game `rand` (386,541 `printf`s, loops 300-30,000) in sync to 30,000 without a hang. Matching build 80 OK. The 2026-10-28 console hang in the opening (mts with runnable tasks, CPU idle, the voice stream printing `*`) is likely the same and is to be checked on hardware. SH1 wasn't rebuilt.

## Step 28: overlay data reset on a stage load; the gun cameras (2026-11-03)

Loop 35,095 (0:18:39.13): the PS1 drew 3 times in loop 35,094, the port twice, both from `GunCame_800C7994`. A port log of the seven cameras (state, counter, turn) against a new BizHawk logger (`tools/port/tas/cam_log.lua`, the Work read at the camera Act 0x800CAA00) showed camera 6 sweeping on the PS1 but in state 5, then 1 on the port from loop 35,050: it had seen Snake. Its sight test passed there (dx 99, dy 121 against 128, no wall), with Snake crossing the edge of its view. A camera tests only on loops where `(GV_Time + field_414) & 3 == 0`, and `field_414` is the overlay counter `s03e_dword_800C32B4`, one per camera created, starting at 0. On the PS1 every stage load copies the overlay again, so it starts at 0; the port's linked-in `s08a` kept the count from the earlier visit, so the phases differed.

Fix: the planned overlay data reset (`docs/Overlay Data Reset.md`). `build/overlays_ps2.py` merges each overlay with an `ld -r` script that puts its `.data` and `.bss` between `Port_Ovl_<ovl>_*` symbols, listed in `stages.c`; `Port_SetStage` (`game/chara.c`, at the stage binary's read and `GM_LoadInitBin`, where the PS1 copies it) keeps an overlay's `.data` at its first load and restores it on later ones, and clears its `.bss`. Commons are left out: on the PS1 they resolve against the main executable's variables. 63 KB of `.data` in all. Checked: `s08a`'s symbols bracket its 1,388 bytes of `.data` and 16 of `.bss`. Now in sync to loop 37,813 (0:20:00.70), `GM_GameStatus` in `s07b`. Matching build 80 OK.

## Step 29: `s07b` (Psycho Mantis) linked in (2026-11-03)

Loop 37,813 (0:20:00.70): `GM_GameStatus` lacked `STATE_SHOW_LIFEBAR` (0x8000): the fight's life bar. `s07b` wasn't linked in (`stage binary 477C is not linked in`): 157 INCLUDE_ASM stubs (`psyco.c` 79, `meryl07b.c` 78), 64 literal addresses, 28 in the stage table. `tools/port/mips2c.py s07b 0x800C3208` translated all 157 (7 extra entry points) with no fixes needed. The stage table's constructors are now symbols from the `s07b` map (prototypes for the four the headers lack); `psyco.c`'s state table at 0x800C33AC (function pointers, read by the translated code) is by symbol; the `const` jump tables are decimals (unused in the port: mips2c.py reads jump tables from the PS1 binary). Matching build 80 OK. The port linked and ran on the first build: in sync to loop 38,579 (0:20:26.61), `GM_PlayerPosition`. No new TLB misses (the 51 known ones in `DG_GetLightMatrix`).

## Step 30: a lui kept across a call in mips2c.py; BizHawk checkpoints (2026-11-03)

Loop 38,579 (0:20:26.61): the PS1's Snake turned toward Meryl and ran to her (from loop 38,577, when the event sets `STATE_PADRELEASE | STATE_PAUSE_ONLY`), the port's ran on. Work dumps of Meryl (identical) and Snake (`work_dump.lua` on the PS1, a printf on the port) showed the first difference: Snake's `control.turn.vy` at loop 38,577, 428 on the PS1, 2,512 on the port. Logging the translated functions entered per loop (a printf in `RECOMP_ENTRY`) found Meryl's state `s07b_800C8BB4`, which sets Snake's turn to `GV_VecDir2(Snake - Meryl) + 2048`. The port's `GV_VecDir2` returned the PS1's 2,476, but the add after it read `v0 + (gap_800B0614 + 492)`: mips2c.py had kept a `lui v0, 0x800B` from before the call and paired it with `addiu v0, v0, 0x800` on the return value. Right only while `gap_800B0614` is at its PS1 address. Fix: a call forgets the caller-saved registers' `lui`. Regenerated: two lines changed in `s07b` (this one, and a load `lhu a0, 38(s0)` in `s07b_800D1484` that had become an address in `MemorySystems`), none in `s08b`. Now in sync to loop 39,732 (0:21:06.15), a `rand` seed.

Each of those PS1 dumps replayed the movie from the start (about 20 minutes). `tools/port/tas/checkpoints.lua` now saves a BizHawk state every 1,000 loops (one pass); `seek.lua` loads the nearest before a logger's first loop. The states first came out at 33 MB each (the movie's input log, stored raw): `run_bizhawk.sh` now sets state compression, and the ones already saved were deflated in place (about 2 MB each). Matching build 80 OK.

## Step 31: overlay statics by name in translated code; Psycho Mantis through (2026-11-03)

Loop 39,732 (0:21:06.15): in loop 39,731 the port drew `GV_RandS` 6 more times than the PS1, from `statue.c`'s `Think0`: the port's Mantis began his statue attack (state 5) where the PS1's stayed in the chair attack (state 4). Mantis's Work (`work_dump.lua` from a checkpoint: 48 s on the PS1 instead of 20 min) and his `TARGET` matched through loop 39,729. A log of the translated functions entered in that loop, and of the pointer Mantis keeps at Work+0x8F0, found it: the chair attack (`s07b_800CDF40`) stores `&chair_alive` there and `s07b_800CC67C` ends the attack when it drops to 0. The PS1 pointer read 1, the port's -1. mips2c.py had written `chair_alive` (0x800C3480, `static` in `chair.c`, so not in the map) as the nearest symbol plus an offset, `s07b_dword_800C3404 + 124`, which lands elsewhere in the port's layout. Five such references, all in `s07b` (`chair_alive`, `pot_alive`, `statue_alive`, `ox_alive`, and `desert.c`'s `desert_damage` as `dword_800C332C + 96`); none in `s08b`.

Fix: those five variables are `STATIC` (`mgstype.h`: global without the keyword, as the repo already does), so the matching build's map names them; regenerated `s07b` refers to each by name. Matching build 80 OK, the addresses as predicted. `mips2c.py` now warns when it writes an address as a word symbol plus 4 or more (none left). The Psycho Mantis fight then plays through: in sync to loop 45,078 (0:23:58.70), a `rand` seed in `s10a`. No new TLB misses.

Next (loop 45,078, 0:23:58.70): `s10a` is not split by the decomp at all (no asm, off in `build.py`), nor are `s11b`, `s11h`, `s15a`, `s17a`, `s18a`, `s19a` on the TAS route; nine more are split but not linked yet. The unsplit ones need a splitter (stage binary from the disc into functions and data, then mips2c.py). Asked the user how to proceed.

## Step 32: stage_split.py: overlays the decomp hasn't split; s10a (2026-11-03)

`s10a` and six more stages on the TAS route (`s11b`, `s11h`, `s15a`, `s17a`, `s18a`, `s19a`) have no asm or source in the decomp. An estimate first: the stage binaries, read from the disc's `STAGE.DIR` (byte-identical to the matching build's for `s07b` and `s08b`), searched for every function of the 79 built overlays with the link-dependent fields masked (jal targets, address halves): about 79% of their 1,020 KB of code is functions that exist elsewhere (434 KB as C, 117 KB as asm), about 209 KB is new (`s17a` 72 KB, `s18a` 48 KB, `s19a` 45 KB). Sister stages: `s11b`/`s11h` share the Hind's code with `s11g`, `s15a` is all `s15c`'s, `s18a` builds on `d18a`. Decompiling the rest would take months; the port needs behaviour, not matching C.

`tools/port/stage_split.py OVL` makes a stage what mips2c.py takes, from the disc: the binary (`build/OVL.matching.bin`), one stub per function (`obj_ps2/stage_split/OVL/`: out of `asm/`, which the matching build collects), a map (the resident symbols, generated names for the overlay's addresses), a linker command file, and `source/overlays/OVL/OVL.c`: all under `MGS_PORT` (the matching build compiles every source), the translated functions and the overlay's .data, .rodata and .bss as blocks in the PS1's layout, so an address read as label + offset is always right (no `chair_alive` bugs). Data words pointing at overlay data, resident symbols or functions become symbols; jump tables keep the PS1's values (mips2c.py switches on them). `source/stage/OVL.c` includes the table by symbol under `MGS_PORT` (the VR build compiles it too). Checked on five split overlays against their maps: the code ranges match; jump tables (found from the `lui`/`addiu` before a `jr`) never hold a function; a data word into code is a function when it follows a return or is a frame setup, else a jump table entry the search missed (`s07b`: 13). Failed first: the code's end at the last `jr ra` (a word in `s08b`'s rodata looks like one: the code now ends at the first rodata address the code refers to past the last frame setup); stubs and pragmas in `asm/` and the C (the matching build failed: `INCLUDE_ASM func too small`).

`s10a`: 532 functions; Wolf's code uses the GTE, so mips2c.py now translates `mfc2`/`cfc2`/`mtc2`/`ctc2`, commands, `lwc2`/`swc2` into the HAL's software GTE (`Gte_DataWrite` etc., declared in `recomp.h`). It linked and ran on the first build: in sync to loop 47,499 (0:25:21.89), a `rand` seed in `s10a`. No new TLB misses. Matching builds 80 OK and 2 OK (`vr_exe`).

## Step 33: the PS1 tick for game logic; whole-RAM diffs (2026-11-03)

Loop 47,499 (0:25:21.89): Wolf's constructor burns `mts_get_tick_count() % 256` `rand()` calls (`wolf2.c`), so the replay matched only while the port's tick happened to agree. From the PS1's 255 draws in loop 47,488 and its seed: a burn of 249, the next trace line's mts tick (90,361; with one less, Wolf's index from `RandU(4096) % 7` came out 4 instead of 0). `trace_to_pads.py` writes `ticks.bin`, `Port_GameTick` returns it in TAS replays; `wolf2.c`, `key_item.c` (the other `% 256` burn) and mips2c.py's calls of `mts_get_tick_count` use it.

Tried and dropped: one emulated PS1 stack shared by the translated functions (stack arguments past the 8th, reads of never-written slots). It moved this desync without fixing it and isn't needed here: reverted (`RECOMP_RETURN` stays, a plain return).

The desync itself is still open: in loop 47,498 the PS1's Wolf enters state 0 (3 draws), the port's doesn't, with her Work, TARGETs, the actor lists, the overlay data and the resident globals equal at the loop's start. New tools for it: `ram_dump.lua` + `host:tas_ramdump.txt` + `ram_diff.py` (both sides' data per symbol in one pass), `actor_list.lua`. Matching builds 80 and 2 OK.

## Step 34: Wolf's burn tick, read mid-loop (Nov 3)

Loop 47,499 (0:25:21.89) was not Wolf's state machine, which is what I had suspected. At loop 47,499, a dump of both sides' RAM (`ram_dump.lua`, `host:tas_ramdump.txt`) showed her Work differing in two words: +2008 (her blink step, `RandU(2)+1` when `GV_Time & 63 == 0`: PS1 1, port 2) and +2012 (the counter it advances: 11 against 22). She is made in loop 47,488, a multiple of 64, and acts in it, so the blink draw comes right after the constructor's `tick % 256` burn. That loop is the stage's load end, where the port's seed is overwritten with the PS1's at the loop's end, so the different draw count didn't show as a seed desync until her state diverged ten loops later. From the PS1's seeds, its blink was an even draw: a burn of 247, not the 249 from the next trace line's tick (90,361). The scenario runs late in a 30-blank loop and the constructor read the tick 2 blanks before the loop's end.

Fix: `trace_to_pads.py`'s `TICK_AT`, a per-loop override of `ticks.bin` (shortcut: found by hand, since the trace samples ticks only between loops; record the tick in `trace.lua` if more are needed). It has one entry, 47,488 → 90,359. In sync to loop 47,546 (0:25:23.46).

Tried and dropped:
- BizHawk's `event.onmemorywrite`/`onmemoryexecute`: no callbacks on this core, and with the System Bus scope the run stalls.
- Setting the PS1's seed when the scenario runs (`gamed.c`): the seeds already matched there; reverted.

## Step 35: a 9th argument for translated calls (Nov 3)

Loop 47,546 (0:25:23.46): in loop 47,545, Wolf fires. The port made two anime actors (logged in `NewAnime`), the PS1 one: the extra was `AN_RecoilSmoke`, the bullet-hit smoke, whose script draws a `rand()` (`ScriptA`'s 0xFE). The bullet's Work, printed in the port's `Act` and dumped on the PS1 (`work_dump.lua`, act 80075dd4), had `speed` 0x02C00000 against 5,000: `NewBulletEx` takes 9 arguments, and mips2c.py's `CALL` passed the stack's only up to sp+28 (8 in all), so the 9th (sp+32) was whatever the callee found there. The bullet then went past its hit distance in its first loop and hit at once.

Fix: `recomp.h`'s `CALL` passes the stack's words up to sp+44 (12 arguments; `stk`'s 32 bytes of padding keep the reads inside the frame). Shortcut: translated callees still take 8 (`RECOMP_ENTRY`'s a0-a7). In sync to loop 47,556 (0:25:23.79). Matching builds 80 and 2 OK.

On the way: `bullet_count` (whose parity gates the other smoke) matched, 84 on both sides; I had misread the port's dump.

## Step 36: the HZD wall/floor tag, diagnosed (Nov 3)

Loop 47,556 (0:25:23.79): in loop 47,555, Wolf's bullet hits a wall. The PS1 makes two sparks (`spark.c`), and the port makes a smoke puff (`AN_RecoilSmoke`, whose anime script draws a `rand()`). The bullet's `seg_flag` was 1 (wall) on the PS1 and 2 (floor) in the port. `HZD_GetOnlineHazard` returns a wall's pointer as is, and a floor's with bit 31 cleared (`online.c:455`). On the PS1 a cleared pointer is still valid, since KUSEG mirrors KSEG0. Callers test bit 31 for "wall": `okajima/bullet.c:337`, `takabe/revbullt.c:178`, `okajima/claymore.c:196` (`< 0`), `s19b jbullet.c:221`. `takabe/elevator.c:944` puts the bit back to compare a floor. Port pointers are all below 0x02000000, so in the port every hit reads as a floor, and elevator.c's floor match fails.

Open, because the fix needs a choice:
- Tag floors with the EE's uncached mirror (`| 0x20000000`, still a valid address) instead, and make the tests `HZD_IS_WALL(p)`. That's one macro, 6 call sites and `online.c`. The risk: a floor read through the uncached mirror can be stale while its cache line is dirty (elevators move floors), so it might need a `SyncDCache` at the tag.
- Have `HZD_GetOnlineHazard` report wall versus floor separately: no aliasing, but every caller changes.

## Step 37: HZD floor tag, option 1 (Nov 3)

The user chose option 1 from Step 36. `libhzd.h` now has `HZD_IS_WALL`, `HZD_TAG_FLOOR` and `HZD_UNTAG_FLOOR`. In the port, a floor is tagged with the EE's uncached mirror (`| 0x20000000`, the same RAM, already used by the HAL's agent mailbox on hardware), and `online.c` writes the floor's cache lines back (`SyncDCache`) when it tags one, so uncached reads aren't stale. The PS1 versions are the original bit-31 expressions. Call sites: `okajima/bullet.c`, `takabe/revbullt.c`, `okajima/claymore.c`, `takabe/elevator.c` (test and untag) and `s19b`'s `jbullet.c`. A comment in `libhzd.h` describes option 2 (a separate wall flag stored next to each pointer) and where it would have to go. No translated stage code calls `HZD_GetOnlineHazard`.

Matching builds 80 and 2 OK. In sync to loop 56,569 (0:29:45.27, `s09a`). This fixed Wolf's walls, and `elevator.c`'s floor match had been failing too.

Found in the run log, still to fix: 50 TLB misses (NULL loads) in `DG_GetLightMatrix` from about loop 27,150 (0:14:16), which predate this change.

## Step 38: no more TLB misses in the TAS run (Nov 3)

The run to loop 56,569 logged 50+ "TLB Miss" lines from five causes. Each was found by logging the bad pointer's owner in the port and dumping the same Work on the PS1 (`work_dump.lua`, `ram_dump.lua`):

- **`DG_GetLightMatrix`, NULL position (from loop 27,190, 0:14:17).** The Ninja's afterimage (`bunsin2.c`) passes `field_108`, which nothing sets. The PS1 reads its BIOS's bytes at address 0, (3, 0, 3152) in every dump, so the port passes those under `MGS_PORT`. This affects only the afterimage's lighting, not polygons in general.
- **`s07b`, stores through NULL at Mantis's Work+0x7DC.** That field is her shadow's "enabled" flag pointer, filled in by `NewShadow2(control, parent, SVECTOR indices, int **enabled)`. The PS1 passes the `SVECTOR` in two argument registers and the EE in one, so the translated call put the vector's upper half (0x000F000C) where `enabled` belongs. The shadow wrote its flag pointer to 0x000F000C, and her camouflage later stored through NULL. Fix: `shadow.c` gains `Port_NewShadow`/`Port_NewShadow2`, which take the PS1's registers and rebuild the vector, and `mips2c.py` renames calls to them. Only these two functions were affected: I checked every C function called from translated code for struct parameters.
- **`s10a 800C4F68`, `GM_WhereList[0]->map->hzd` while no player exists (the `s10a` load, loops 44,879–45,071).** `GM_WhereList[0]` is `DummyPlayer`, whose `map` is NULL. The port gives it a zeroed `MAP` (`control.c`, `MGS_PORT`), so `hzd` reads as NULL, which is what PCSX2 already returned.
- **`s10a 800C5B48`, NULL+0x48.** This is `s10a`'s copy of `NewDemoKage` (`DEMOID_SHADOW`), which `demoexec.c` calls through an unprototyped pointer with an `SVECTOR` by value, the same ABI split in the other direction. Fix: `stage_split.py`'s `ABI_WRAP` points the stage table and data at `Port_s10a_DemoKage` (`port/src/hal_game.c`), which takes the vector as C passes it and calls the translated code with the PS1's registers.
- **Translated functions now take 12 arguments,** like `CALL` passes (`RECOMP_ENTRY` puts a4–a11 at sp+16..44, `stk` has 48 bytes over the frame; `s10a 800C5EF4` reads a 9th). The first try crashed in `s08b` at loop 31,411. With 12 parameters GCC turned a final `CALL` into a sibling call, which wrote arguments 9–12 into the incoming argument area. A C caller passing one argument (`GV_ExecActorSystem` calling an `Act`) has no such area, so that write landed on its saved `ra`, and the jump went to 0x1000. `CALL` now ends with an empty `asm volatile`, so it is never a tail call.

The run to loop 56,569 has 0 TLB misses. Sync is unchanged (still in sync to 56,569). Matching builds 80 and 2 OK. Regenerating `s10a` with `stage_split.py` and `mips2c.py` reproduces the committed files.

## Step 39: the stage overlay process, written up (Nov 3)

`docs/Stage Overlay Translation.md` describes the whole path for a stage that isn't hand-decompiled:
- the tools: `stage_split.py` (from the disc), `mips2c.py`, `recomp.h`;
- linking and the per-load data reset;
- the ABI rules where translated code meets C: 12 arguments, no sibling calls, struct-by-value wrappers both ways;
- the PS1 memory behaviours to look for: NULL reads, bit-31 tags, the tick;
- the debugging tools, and a checklist for the next unsplit stage.

`mips2c.py`'s docstring now points there.

## Step 40: loops 56,569 and 57,290, both from a load's end (Nov 4)

**56,569 (0:29:45.27, `s09a`).** Counting LCG steps from the shared seed of loop 56,568 gave the PS1 8 draws in the loop and the port 9. A temporary caller log in the HAL's `rand()` (return address, resolved with addr2line) found the extra one: `GV_RandU(16)` from `s12c_dog_800CB42C`, a dog rolling its next action when its animation ends. The PS1 makes the same draw a loop later (9 draws at 56,570). Diffing the dogs' Work (`work_dump.lua` against a port printf) showed the same values on both sides, shifted: dog 0 one update ahead in the port and dog 1 one behind. A fixed one-loop shift between the dumps doesn't line them up, because the PS1's dump is taken at a frame end, which can fall in the middle of a game loop. The dogs take turns by `sel = GV_Time % 3`. A dump of the port's first dog Acts showed one at loop 56,322, before the jump to 56,486. The replay gave GV_Time the PS1's number at the next loop's trace, but the stage script makes its actors in the load's last loop (gamed.c, right after `GM_LoadRequest = 0`), and they act in that same loop. 163 % 3 = 1, which is the shift. Fix: `Port_TasScenario` (tas_replay.c), called there under `MGS_PORT`, sets GV_Time to the PS1's load-end loop before the script runs. `Port_TasTrace` no longer renumbers, but still takes the PS1's pads at every load end (loop 9,633).

**57,290 (0:30:06.47, `s10a`).** The port made 4 extra draws a loop: a rat's segment start (`s00a_mouse_800D3E9C`, translated as `s10a_800CF88C`), two loops before the PS1's. The rats' wait rolls (`8 + GV_RandU(16)`) were the PS1's sequence two draws later (port 8, 19, 18, 18, 13; PS1 15, 16, 8, 19, 18). The load-end loop drew 149 times in the port and 147 on the PS1. The trace showed both as 147, because the seed becomes the PS1's after that loop. 143 of them are Wolf's creation burn, `tick % 256` (`s10a_800D7A98`, `Port_GameTick`). The PS1 burned 141, so its tick was 107,405, 2 blanks before the next line's 107,407. That's the same offset as at 47,488. It's a second `TICK_AT` entry, still a hand-found shortcut (see trace_to_pads.py). Also a new TLB miss in that loop: `sub_8004EB74` (Snake's first-person entry) reads `field_9B0_pad_ptr->dir` with the pointer NULL. The PS1 reads its RAM at 8, 0x0008 in every dump, so the port uses 8 there (`MGS_PORT`).

Tried and not useful: diffing whole Work dumps with a fixed one-loop shift (sampling noise, see above); a rand caller window set at the previous loop's trace misses a load-end loop, which is renumbered mid-loop.

Matching builds 80 and 2 OK. In sync to loop 59,444 (0:31:17.28, `s03b`), no TLB misses. The next desync is GV_Clock, the pads and `DG_UnDrawFrameCount` together.

## Step 41: faster desync hunts (Nov 4)

The hunts in Step 40 took about eight replays, mostly to rebuild with a moved log window. Now:

- **Rand caller log, built in.** The HAL's `rand()` calls `Hal_RandHook` (NULL unless a game sets one; the SH1 port is unaffected). Under `MGS_PORT`, util.c's `GV_RandU`/`GV_RandS` record their caller in `Port_RandFrom`. `run_port.py --rand-log A-B` writes `host:tas_randlog.txt`, and `tas_replay.c` then prints each draw in loops A to B. The window is checked at each draw, so a load-end loop renumbered mid-loop (Step 40) is logged under the PS1's number. At the end of the run, `run_port.py` resolves the addresses (function and source file, since static `Act`s share names) and prints each loop's draws in order, with totals. Check: loops 1,000–1,004 give 15, 12, 13, 13, 12 draws, the PS1's counts from its seeds. Moving the window needs no relink.
- **Null GS renderer for sync runs.** `pcsx2_run.py` (SH1 port's tools) has `--renderer sw|null`, default `sw`. `run_port.py` uses null unless `--shot` (frame dumps need drawing) or `--sw` is given. The user approved this exception to the software-renderer rule; hardware is never used, since the VM has no GPU. To loop 10,000: 37 s null, 45 s software. The whole run to 59,444 takes 211 s and reaches the same desync.

Correction: Step 40's replays took about 5 minutes each, not 30. My early rate (30 loops a second) was measured while a link and a BizHawk run were also using the machine. The PCSX2 log shows about 250 loops a second.

**Parallel runs.** `run_port.py --dir D` runs in folder D, with its own trace, log, `host:` switches and shots. D gets hard links to obj_ps2's ISO, ELF and the replay tables the port reads from `host:` (`tas_pads/raw/time/loads/ticks/timeline.bin`), as they are when the run starts. The PS1 screenshot cache stays shared. My first parallel test linked only the ISO: the port then found no tables and didn't replay at all. That also invalidated the earlier raw PCSX2 throughput test. Redone with real replays to loop 20,000: 1 run 72 s, 2 at once 77 s, 3 at once 90 s, all in sync. That's 1.87x and 2.4x serial throughput on 8 cores and 15 GB.

## Step 42: loops 59,444 to 72,998 (Nov 4)

Three fixes to the replay and two to the comparison took the run from 59,444 (0:31:17.28) to 72,998 (0:38:21.72).

- **The PS1's frame holds (loop 59,444).** Under `STATE_NOSLOW` (2 vertical blanks a loop), dgd.c sets `DG_HikituriFlag` when the PS1 falls behind; that loop skips its vertical blank wait, and gvd.c doesn't flip `GV_Clock`. The port keeps pace and never holds, so the double-buffer parity stayed one off from there. `Port_TasTrace` now undoes the port's flip when the PS1's clock (the time table's) didn't change from the previous loop. BizHawk's mid-loop clock samples (`compare_trace.py`'s `fix_clock`, loop 14,030) are now fixed in the table too (`trace_to_pads.py` imports `fix_clock`). Without that the 14,031 line looked like a hold. First try: the hold check in C skipped the three-equal-lines pattern itself, which still read 14,031 as a hold.
- **Late PS1 samples.** A held loop has no wait, and in busy rooms (s03c: 60 maggot draws a loop) BizHawk can sample in another wait inside the loop (the known open question in `trace_to_pads.py`). That PS1 line then already shows some of the loop's actors: the press on two lines at 59,444, Snake's step and the play time's second at 60,532, Johnny's draw at 61,444, `STATE_VOX_STREAM` at 61,449. `compare_trace.same()` now accepts a PS1 value equal to the port's next line, and a seed on the LCG's way from the port's line to its next; `run_port.py` compares each line once the next one is in. `GV_Clock` and `GV_PassageTime` are set before any sample and are still compared exactly. A first version only skipped hold lines (`skip_holds`); it was deleted when this covered them. Limit: the seed check proves only similar draw counts, not the same values per caller (it let the real desync below through for 6 loops, then the status caught it).
- **Loops without a line (60,536).** Two loops in one video frame leave a loop with no trace line. Its time-table record was all zeros, so the replay set the play time (and the clock the hold check reads) to 0. Such a loop now has the next line's clock and play time. I also tried giving it the vertical blanks between its neighbours as its passage time; it changed nothing here, so it's not in.
- **Stream start a loop late (61,305).** Johnny talks for a count of loops of `GM_StreamStatus() == 2`; then he moves and later draws `GV_RandS(128)` to decide whether to talk again. Found by elimination: the torture actor and pad_demo weren't involved (the bit at 61,558 is `STATE_VOX_STREAM`, not `STATE_NOSLOW`); `GM_VoxQueueDelay`'s caller was Johnny; his Work dumped on both sides (`work_dump.lua`, act 800C9F7C, against a port printf) matched to 61,305 and his walk was a loop behind from 61,310. The start gate let the port start in the PS1's loop, 61,305, but strctrl.c's state 1 waited for the port's stream task (`FS_StreamTaskState() < 0`), a loop late. In replays state 1 no longer waits once the PS1 has started the stream (`Port_TasStreamMayStart() == 1`, -1 outside replays): state 3 already waits for the data.

Ruled out on the way: the actor order (levels run 0 to 9; uji 4, Johnny 5), a CD read pause at the s03c load (`GV_PauseLevel` logged per frame in BizHawk: 0). BizHawk has no execute hooks on this core (noted earlier), so the PS1's rand callers can't be logged directly.

Next desync: 72,998 (0:38:21.72, s11a), `GV_PadData` (a stick value, `0829` against `1029`). Matching builds: 80 and 2 OK.

## Step 43: s11a linked in (Nov 4)

- **72,998 (0:38:21.72):** one PS1 line has `GV_PadData`'s word at offset 8 as `0x1029` instead of `0x0829`, after a 56-blank loop; the lines before and after match. Let through with `--ignore "GV_PadData@72998-72998"`: nothing differed after it until 73,234.
- **73,234 (0:38:29.61):** `GM_EnemyWatchCount` (score screen) 1 against 2. The PS1's s11a commander (`zk11acom.c`, `UpdateGameFlag`: Snake in zone 24 on the stairs) counted it; a printf there never ran in the port. s11a was one of the 19 overlays left out of the port link: its character table (`source/stage/s11a.c`) gave its 12 constructors as literal addresses, because `charalst.h` had `?` for `CHARA_ZAKO11A` and `CHARA_ZAKO11ACOM`. They're now `NewZako11A` and `NewZako11ACommander`, and the table uses the `CHARA_*` names like the other stages. The matching build still matches (80 and 2 OK), and the port links s11a in. In the port, s11a had been running with no actors of its own.
- **TLB misses:** 50, all in boxall.c's `DrawItemText` (torture room, loops 60,535 on): `GM_PlayerControl` is NULL there and the PS1 reads its RAM at 0 (`0003 0000 0c50 275a`). The port uses those values when it's NULL. None left in the run.

Now in sync to 76,316 (0:40:10.44, s11b): `STATE_CUT_IN` (0x40) set on the PS1 five loops after a load end.

## Step 44: s11b, s11g and s11d in the port; the port's own holds (Nov 4)

- **s11b (76,316):** "stage binary 4ABC is not linked in": the decomp hasn't split s11b. `stage_split.py s11b` and `mips2c.py s11b 0x800C3208` (228 functions). The generated table didn't compile: it named `NewAnime_8005E258`, a resident constructor `charalst.h` doesn't declare. `stage_split.py` now declares resident names `charalst.h` doesn't list; s10a regenerates unchanged.
- **s11g (77,164):** 8 INCLUDE_ASM stubs, translated by `mips2c.py s11g`. It was still left out for 66 "literal symbol addresses": its jump tables (`jpt_800DD2C4`, hindbody.c's `s11g_dword_*`). The translated code loads a table word and switches on the PS1 address, so they must stay literal. `overlays_ps2.py` no longer counts a literal that appears as a `case 0x...:` in the overlay's translated code; s11e and s11i (other literals) stay out.
- **s11d (77,671):** 37 stubs, translated by `mips2c.py s11d`.
- **77,697:** the port's clock held on two loops the PS1 didn't. Under `STATE_NOSLOW` the port sets `DG_HikituriFlag` when it falls behind its own pace, which depends on the host. `Port_TasTrace` now flips whenever the PS1's hold and the port's disagree, both ways.

Matching builds 80 and 2 OK after each; no TLB misses. Next desync: 79,264 (0:41:44.05, s11i), the rand seed. s11i is still left out (3 literal addresses).


## Step 45: s11i, s11h, and mips2c's constants (Nov 4)

- **79,264 (0:41:44.05, s11i):** s11i was left out for 3 literal addresses: zako11f/action.c's item-name table gave
  its strings as `0x800D5260` etc. They're now the strings' symbols (`s11i_dword_800D5260`, ...); the matching build
  still matches and s11i links in.
- **84,331 (0:44:22.39, s11h):** "stage binary 4AC2 is not linked in": s11h had no source. `stage_split.py s11h`,
  `mips2c.py s11h 0x800C3208` (235 functions, no warnings).
- **84,553 (0:44:30.28):** the PS1 fired a Hind bullet (bullet.c + `AN_HeavyFlash`, 5 draws) 3 loops before the port.
  The fire routine (`s11h_800DA02C`) fires every 3rd loop, but skips when its aim vector, a column of the body's world
  matrix, has length 0. The port's matrix was noise (scale 29136, -350, 0, 2649 loop to loop). A PS1 RAM dump at
  84,551/84,552 (`ram_dump.lua`; the Hind's Work found by its Act pointer) gave a scale of ~620 and Y ≈ 2,900; the
  port's Hind Y position started at 15,578,195. Cause: `mips2c.py` paired `addiu v0, v0, 5000` with a `lui v0, 0x800B`
  from elsewhere in the function, making `+ 5000` the address `gap_800B0614 + 3444`. That was a fallback from s08b for a
  `lui` in a branch's delay slot: any `addiu rX, rX, imm` with |imm| >= 0x1000 took any `lui rX` in the function. It's
  deleted; the delay-slot case is handled by `pending` (added later). One case still needed it: s11d's
  `printf("invalid attack mode")`, where the `lui` is in an earlier branch's delay slot and a `j` reaches the printf. A `j`
  now carries the live `lui` values to its target. Regenerating all seven translated overlays changed only constants that
  had been read as addresses: s10a 1, s11b 28, s11g 21 (its Hind); s11d none; s11h is new.
- **The PS1's holds, all of them.** `DG_HikituriFlag` also picks the DG channels (chanl.c: only the screen channel when
  held) and frame.c's draw and normal-heap clear, but the replay copied the PS1's holds only into `GV_Clock` (Step 42).
  dgd.c's Act1 now takes the flag from `Port_TasHold()` in replays (the PS1's clock for this loop and the next, from the
  time table), and the after-the-fact clock flip in `Port_TasTrace` is gone. This was my first guess for 84,553; it
  didn't change that desync, and the full run stays in sync with it.

Tried and not useful: a `TICK_AT` entry for the s11h load-end loop (the Hind's sound timer reads the tick; reverted).

Open: two TLB misses at loop ~84,515 (s11h, `s11h_800C6490`, DEMO_SHADOW's Act, `demokage.c`): its parent's `objs` is
0x20, so the parent was freed. Not fixed yet.

Matching builds 80 and 2 OK. In sync from the start to 84,844 (0:44:40.23, s11h): `GM_GameStatus` 0x20 set on the PS1.

## Step 46: a stream's wait for the PS1's start (Nov 4)

**84,844 (0:44:40.23, s11h):** `STATE_VOX_STREAM` cleared in the port after 6 loops, the PS1's after 81. A temporary
caller log in `GM_VoxStream`/`GM_StreamPlayStop` showed the Hind's Act (`s11h_800D0790`) stopping vox 87158 at loop
84,842: it stops a stream whose `GM_StreamStatus()` is 1 (strctrl state 2, waiting to start). The time table puts the
PS1's clock start at 84,843. Until then the PS1's strctrl stayed in state 1 (status 0) waiting for its stream task,
then went through 2 to 3 in one loop. The port's task was ready sooner, so it waited in state 2 for the PS1's start
(`Port_TasStreamMayStart`, Step 42). Now in replays a stream with sub state 0 (free to play, so nothing but the clock
start holds it in state 2) waits in state 1 until the PS1 starts it. A stream waiting for `GM_StreamPlayStart` still
goes to state 2 when its task is ready.

Matching builds 80 and 2 OK. In sync from the start to 86,037 (0:45:20.40, s11h), the rand seed.

## Step 47: square roots of overflowed sums (Nov 4)

**86,037 (0:45:20.40, s11h):** the PS1 drew 1 more in loop 86,035 and ~240 more in the next (an explosion). PCSX-Redux's
PS1 screenshot timed out this deep in the movie (interpreter, 900 s), so I compared the Hind's whole Work instead: a
port hex dump at the Act's entry against BizHawk RAM dumps (`ram_dump.lua`, the Work found by its Act pointer). The
Hind's missile (+1888: position, +1928: heading) flew toward Snake on the PS1 and was stuck far off in the port. A
per-loop BizHawk log of those fields (a scratch script on `seek.lua`) against a port printf: the missile launches at
85,909 on both sides, and the port's first step is already wrong.

The heading is `ratan2(SquareRoot0(dx² + dz²), dy)` (`s11h_800D347C`), with dx and dz around 62,000: the sum
overflows to a negative int. libgte's `SquareRoot0` then normalises it to a table index of -320 to -129, and the PS1
reads the halfwords before `SQRT` (0x800A4C00), the end of `rsin_tbl`. The HAL's port read whatever its link put
there. The HAL now keeps those 192 halfwords (`SQRT_NEG`, from a PS1 RAM dump) for `SquareRoot0`/`SquareRoot12`
(psx-to-ps2-HAL 2944fbc). Check: at 85,905, a = -411,533,807 gives 15,968, so heading 406, the PS1's. My first table
had only 64 entries (I took the range of the shift alone); a sum with 2 leading ones (85,911) reaches further, and the
desync moved to 86,035 until the table covered it.

Matching builds 80 and 2 OK. In sync from the start to 91,876 (0:48:33.11, s11e): `GM_GameStatus` 0x10000000 on the
PS1. s11e is still left out of the port (7 literal addresses).

## Step 48: s11e linked in (Nov 4)

**91,876 (0:48:33.11, s11e):** s11e was left out for 7 literal addresses in `overlay2.c`: the item-name table
(`s11e_dword_800C3690`, read by zk11eaction.c as `const char *[3]`) and the soldiers' put-function table
(`s11e_dword_800C369C`, `void *[]`) were ints holding the PS1 addresses. They're now arrays of the strings' and
functions' symbols, as for s11i in Step 45. Matching builds 80 and 2 OK; the port loads s11e's actors.

Now in sync to 91,969 (0:48:36.25, s11e): `GM_AlertMode` 3 on the PS1, 0 in the port.

## Step 49: overlay structs kept in order; s11e's removed soldiers (Nov 4)

- **91,969 (0:48:36.25, s11e):** alert 3 on the PS1 right after the cutscene, 0 in the port. A BizHawk log of the
  commander (`ZakoCommand_800DF280`) showed its alert going 0 to 255 in loop 91,967 on both sides, but the port's `mode`
  was 70,254,592 (and counting), so the switch that calls `GM_AlertModeSet(3)` never ran. s11e's `overlay4.c` defines
  the commander as a run of `int`s, and in the port `SECTION` is empty, so they're common symbols that the linker laid
  out in another order (`nm`: the struct's "mode" was another variable). s03d's `overlay3.c` had the same fix: its
  `.bss` goes in a named section, which keeps the file's order. A scan for `int` bss words that other files declare
  as a struct or array found 9 files: s11e and s11i (commanders), s08b, s05a, s19b (2), d18a, camera, rank. All get the
  same 6 lines (only s11e, s11i and s08b are linked in today).
- **TLB misses at 0x638478/548 (48):** s11e's commander reads `sn_dis` and writes `field_BFC` for a removed
  soldier's NULL entry, as s03d's `zakocom.c` did. The PS1 reads 0 at 0xC2C (every RAM dump) and writes 0xBFC; the port
  uses 0 and skips the write.
- **Still open:** s11h's DEMO_SHADOW Act (`s11h_800C6490`) reads a freed parent (2 misses, loop ~84,515). The PS1
  reads its own heap there; it only draws (visible or not), no game state.

Matching builds 80 and 2 OK. In sync from the start to 93,337 (0:49:16.90, s12a), the rand seed.

## Step 50: the tick table by loop (Nov 4)

**93,337 (0:49:16.90, s12a):** the PS1's load-end loop made 2,701 draws, the port's 2,479. The rand log: Wolf's
`wolf2_GetResources` burns `Port_GameTick() % 256` draws and made 26, where the tick table's line for that loop says
249. `trace_to_pads.py` wrote `ticks.bin` one entry per trace line, but `Port_GameTick` reads it by `GV_Time`. Since
the first loop without a line (60,536, Step 42) every tick read came from a later loop, 7 lines late here. `ticks.bin`
is now by loop, like `time.bin`: a loop without a line takes the next line's tick. The earlier `TICK_AT` entries
(47,488, 57,275) were before 60,536 and are unchanged. That gave 2,702 draws, one more than the PS1: as in s10a, Wolf
reads the tick a blank before the next line, so `TICK_AT` gets 93,335: 176,376. That's the third hand-found entry,
all Wolf's burn in a load-end loop; the comment says to record the tick in trace.lua if more appear.

Matching builds unaffected (tools only). In sync from the start to 94,060 (0:49:41.80, s12a), the rand seed.

**94,060 (0:49:41.80, s12a):** snow flake respawns (105 draws each, `Snow_800C59C8`) at different loops. A BizHawk
log of `gUnkCameraStruct2_800B7868` against a port printf: the cameras match (the PS1's line T+1 is the port's
state at Act time in loop T). The flakes are placed at creation, in the load-end loop 94,052, where Wolf is made again:
the port made 2,645 draws there and the PS1 2,644, so Wolf burned 191, not the table's 192. Fourth `TICK_AT` entry:
94,052: 177,855. The seed becomes the PS1's at a load end, which hides the load-end loop's count, but the flakes made
in that loop got other positions.

In sync from the start to 95,874 (0:50:51.43, s13a): `linkvarbuf` [4], [6] to [10] and [74].

**95,874 is the disc swap.** The PS1 goes from the `change` stage (disc 1 → 2, TAS frames 181,883 to 181,906) to
s13a. The port stays in `change`, printing `CD CASE CLOSE!!`: the disc swap isn't built yet (Planning Doc, `libfs`:
`DISC2.BIN` is on the image, but `change`'s drive checks and the switch aren't). Everything after this in the TAS
needs it. Waiting for the user's decision on how the port should present the swap.

## Step 51: automatic disc swap (Nov 4)

The user's decision: switch discs automatically for now; later every file will be on one DVD and no swap is needed.
`change.c`'s state 2 waits for the tray to open. Under `MGS_PORT` it now calls `MgsCd_Swap()` (cdbios_ps2.c: the other
`DISC*.BIN` becomes the drive's disc) and sees the tray open. The stub already reports the tray closed, so state 3
goes on to state 4, which waits for START (the TAS's press). Then state 8's check reads disc 2 and prints
`THIS IS DISC 2!!`. I keyed this to the change screen, not to `CdlStop`, because demosel.c, open.c and ab_ch.c also
send that. ab_ch.c (abst) has its own tray states and isn't changed.

Matching builds 80 and 2 OK. In sync from the start to 97,879 (0:51:47.37, s14e): `GM_PlayerPosition`. s13a loads
with "stage binary 4B1F is not linked in".

## Step 52: s14e linked in (Nov 4)

**97,879 (0:51:47.37, s14e):** "stage binary 4B1F is not linked in" is s14e. It was left out because 30 of its objects
are assembly in the decomp (`asm/overlays/s14e/*.s`, no C file). A same-named .c would give the matching build two
rules for one .obj, so the port gets `source/overlays/s14e/asm_objects.c` (all under `MGS_PORT`), which includes mips2c's
translations of those objects. `build/overlays_ps2.py` takes it in place of a missing source when it includes that
object's `.inc`. mips2c already translates every `.s` of an overlay.

Then 57 literal addresses: data words holding function or string addresses (`zako14_data.c`, `overlay3.c`) and the
stage table. `tools/port/symlits.py OVL FILE...` (new) rewrites such initializers as `(int)SYMBOL` from the link map
and keeps words that translated switches compare against (`case 0x...:`). I had to fix declarations by hand: they must
go after the file's first includes, not after a recomp include, and the strings are `const char`. The stage table uses the
`CHARA_*`/`DEMO_*` macros like s11a's, except `CHARA_FOG`: `NewFog` (fog.c) is assembly in s14e, so that entry is
`s14e_800D8604`. Matching builds 80 and 2 OK.

TLB misses: s14e's commander (`zako14com.c` `ChangePrio`) has the same NULL soldier read and write as s11e's (Step 49),
fixed the same way.

In sync from the start to 101,236 (0:53:40.90, s15a), the rand seed. s15a ("4B3B") isn't split yet, and it's on disc 2.

## Step 53: s15a, from disc 2 (Nov 4)

**101,236 (0:53:40.90):** s15a ("4B3B") isn't split and is on disc 2. `stage_split.py` read only disc 1's STAGE.DIR.
It now tries disc 1, then disc 2 (s10a regenerates unchanged). Then `stage_split.py s15a` and
`mips2c.py s15a 0x800C3208` (274 functions, no warnings). Matching builds 80 and 2 OK.

In sync from 100,000 to 101,734 (0:54:00.52, s15a), the rand seed.

**101,734 (0:54:00.52, s15a), open.** A single `NewSpark` draw (spark.c's `InitRandamTable`) happens at 101,728 on the PS1 and at
101,730 in the port: a bullet hits 2 loops later. Bullet Works dumped on both sides (port printf in bullet.c's Act; on the PS1 a
scratch BizHawk script scanning RAM for the Act pointer 0x80075DD4 at actor +8, in 4 KB `readbyterange` chunks: one call over
1.4 MB returned nothing). Field offsets on the PS1: pos 0x110, hitpos 0x118, step 0x120, hit_dist 0x138, dist 0x13C. Every
bullet fired from 101,693 on (the shooter is `s15a_800CB2F8`'s actor, every 5 loops, with `s15a_800CB24C`'s 4-draw spread)
starts about 20 units off and points slightly differently (step z -155 against -166, ...), and some hit different surfaces
(hit_dist 22,620 against 20,272). The rand seed matches all along, so the spread draws are the same: the shooter's own
position and aim differ in the port, from before 101,690. Next: dump that actor's Work on both sides, going back to find
when it starts to differ.

## Step 54: Raven's timer tick (Nov 4)

**101,734 (0:54:00.52, s15a), solved.** Step 53's notes chased the bullets' aim to Vulcan Raven (`CHARA_VALCAN`,
Act `s15a_800C99F0`). BizHawk logs of Raven's Work (found by the Act pointer) against port printfs:
- His position matched. His facing (`turn.vy`, Work +0x72, set by `s15a_800CC8DC` as `ratan2(target - own) +
  GV_RandS(64)`) differed from loop 101,484: 350 against 377.
- The `ratan2` inputs matched, and the PS1's turn is the second draw from the shared seed (-14) where the port's is
  the first (+13), so one draw comes before Raven's on the PS1.
- That's his own timer (`s15a_800CD9A4`): when `tick - Work[2284] > Work[2272]` he draws `GV_RandU(64)` and stores
  the tick. Logged on both sides: when Raven is made in the load-end loop 101,313, the PS1 stores tick 192,415 and the
  port the table's 192,418, so every trigger came a loop late.

`TICK_AT` 101,313: 192,415. Wrong turns I took on the way: a stale-target theory (the PS1's frame-end samples look one
loop behind; the inputs matched), and the camera's noise shake (`GM_NoisePower` is 255 at 101,486 on both sides).

That's the fifth hand-found `TICK_AT` entry, all from an actor made in a load-end loop reading the tick 1-3 blanks
before the next line. trace_to_pads.py's comment says to record the tick in trace.lua once they're common; it's worth
doing now.

In sync from the start to 101,983 (0:54:10.85, s15a), the rand seed.

## Step 55: the tick at a loop's start (Nov 4)

**101,983 (0:54:10.85, s15a):** Raven's timer (`s15a_800CD9A4`) fired a loop early in the port. A BizHawk log of his
timer over 101,480 to 101,990 against a port printf, and the stored ticks against the tick table: all 10 PS1 values are
exactly the loop's start tick + 1 (the previous loop's end sample + 1). The table's "next line's sample" was 1 or 2 later,
depending on how long the loop ran. `ticks.bin`'s default is now that start + 1; `TICK_AT` still covers the reads late in
a long load-end loop (Wolf's burns, Raven's creation). First I tried "end sample - 1": no regressions, but it didn't
fix 101,983 (some loops are 3 blanks long).

In sync from the start to 105,450 (0:56:00.79, s16b): `GV_PadData`.

**105,450 (0:56:00.79, s16b), open.** The PS1 closes a codec call at 105,432 (both sides) and 18 loops later starts a
demo (`GM_GameStatus` 0x10CA0000, pads masked). The port stays in play: the PS1's demo is missing, which then shows
as `GV_PadData` and Snake moving. A temporary printf in `GCL_Command` over 105,425 to 105,470: the port runs one
command, 0x64C0 at 105,431 (the codec's exit callback, proc B9E5), and nothing at 105,449. `delay.c` is a plain
counter, so whatever starts the demo on the PS1 (a trap on Snake's position, or an s16b actor's `GCL_ExecProc`) doesn't
fire in the port. Snake's position matches through 105,449. Demos on disc 2 do play in the port (95,875). 0x64C0 is `eval`: the callback only sets script variables, and `linkvarbuf` matches through 105,450, so whatever polls
them and starts the demo 18 loops later is what differs. Next: find what runs the demo script on the PS1 (BizHawk:
the s16b actors at 105,449, `actor_list.lua`).

