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
