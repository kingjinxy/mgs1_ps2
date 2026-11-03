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
