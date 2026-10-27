# Planning Doc — Metal Gear Solid Integral (PS1) → PS2 Port

Living plan for the port. Check items off as they land; record *how* each change was made in a
`Running Walkthrough.md` alongside this file. Modelled on the Silent Hill port
(`../silent-hill-1-ps2-port/Planning Doc.md`), whose PSY-Q compatibility layer this port reuses.

## Strategy

Recompile the decompiled C for the PS2 Emotion Engine with ps2sdk, and replace Sony's PSY-Q
libraries with the PS1 compatibility layer (HAL) already built for the SH1 port. Game code stays as
close to the decomp as possible.

Ground rules:

- **The matching PS1 build must keep matching.** Port changes go behind `MGS_PORT` (or behave
  identically on PS1), and `python build.py` must still produce the expected SHA256 for
  `SLPM_862.47`/`.48`/`.49` and every overlay after each change. This keeps upstream merges cheap and
  gives a free regression test.
- **One HAL, two games.** The HAL lives in one shared place; game-specific behaviour (file systems,
  buffer addresses, overlay tables) stays in each game's tree. Anything SH1-specific found in the HAL
  gets pulled out, not forked.
- **32-bit pointers are an asset.** The EE uses 32-bit pointers, so struct layouts, GCL script data
  and loaded-file relocation stay valid as-is.
- **Prefer bit-exact over fast.** Use the SH1 software GTE first; vector-unit work only after
  profiling.
- **No upstream contributions for now.** This port uses AI-written code, so nothing is sent to
  `mgs_reversing`. Upstream decomp work is merged *in*; matching is kept for that and as a check.

## Decisions

- **Target the Integral discs first** (`SLPM_862.47`/`.48`). The VR disc (`.49`) comes later.
- **Keep the PS1 limits for now** (memory, VRAM, frame budget). Raising any of them is a later,
  separate decision.

## Reference material

`/home/alex/Documents/psyq_docs` holds the PSY-Q 4.1 English Technical Reference PDFs: the HAL
API reference is `DEVREFS/LIBREF41.PDF` and `LIBOVR41.PDF`, and data formats (TIM, TMD, VAB, STR)
are in `FILE41.PDF`. Sources: `/media/sf_VirtualBox_Shared_Folder/ps1_sdks`. MGS links against
4.4, so check 4.4 behaviour against `psx/441chg.txt` in `Runtime Library 4.4.7z` where it matters.

## Matching build

From `build/` (Wine here is 64-bit only, so a `wine` shim runs the PSY-Q tools through wibo):

```
PATH=/home/alex/.local/share/wibo-as-wine:$PATH /home/alex/.venvs/mgs_reversing/bin/python build.py
```

Verified 2026-10-27: all 80 outputs match, and the VR executable (`--variant=vr_exe`) matches too.

## Current state of the codebase (as of 2026-10-27)

- Main executables (`SLPM_862.47`/`.48`/`.49`) are 100% decompiled.
- Overlays: 19 directories under `source/overlays`, ~747 `INCLUDE_ASM` stubs left in total, heavily
  concentrated: `s07b` 157, `s08b` 122, `s14e` 111, `rank` 97, `d18a` 59, `s19b` 50, `brf` 43,
  `s11d` 37, `s15c` 26, `s03d` 21, `camera` 16, `s11g` 8.
- Build: `build/build.py` generates ninja rules for the original PSY-Q 4.4 toolchain
  (`cc1psx.exe`/`aspsx.exe`/`asmpsx.exe` under wine/wibo). There is no GCC/splat Makefile as in SH1.
- PS1-specific code outside overlays: `gte_*` in 30 files, `0x1F80…` scratchpad literals in 8,
  `0x80xxxxxx` literals in 156. The last group has not yet been sorted into real fixed addresses and
  harmless constants such as colours or flags.
- Subsystems of interest: `libdg` (renderer: OT, prims, GTE transforms), `libgv` (core/actors),
  `libgcl` (script interpreter), `libfs` (CD/file loading), `libhzd` (collision), `memcard`,
  `sound` (custom `sd_*` driver), `libsio`.

## Steps

### Step 0 — Share the HAL  *(do first)*

- [x] Move the SH1 HAL into `../psx-to-ps2-HAL` (sibling directory, own git repo; GitHub later).
      File-by-file sort, hooks and what's left: `../psx-to-ps2-HAL/docs/Split Plan.md`. SH1 branch `hal-split`
- [x] Audit it for SH1 assumptions and move each behind a per-game hook (`HalGame_*`, weak defaults) or a
      setting (`hal_game_config.h`)
- [x] SH1 port still builds and runs after the move (same link; PCSX2 logs identical; GTE tests pass)
- [ ] Later HAL cleanups (not blocking MGS): `SH_PORT_*`/`sh1*` renames, generic tools, general disc map
- [ ] Fill the gaps MGS needs that the SH1 layer lacks, borrowing from psyz
      (`github.com/Xeeynamo/psyz`, decompiled PSY-Q in `decomp/src`; check its licence before copying):
  - [x] libspu: `SpuMalloc`, `SpuSetIRQ`/`IRQAddr`/`IRQCallback`, `SpuSetNoiseVoice`,
        `SpuSetPitchLFOVoice`, `SpuSetReverbDepth`, `SpuGetAllKeysStatus`. The SPU interrupt is MGS's sound
        clock (voice 23 looping a silent block, 98.44 Hz): delivered IOP → SIF command → EE thread, with the
        PS1 thread switch `mts_isend` asks for (`tools/spu_irq_test`, PCSX2)
  - [x] libcd: **not emulated further** (decided 2026-10-27). MGS's `libfs/cdbios.c` streams with
        `CdlReadN` + a per-sector ready callback + `CdGetSector`; the HAL's libcd only has SH1's
        `CdRead` path. Instead, under `MGS_PORT`, `cdbios.c`'s internals (`CDBIOS_Reset`, `ReadRequest`,
        `ReadSync`, `ForceStop`, `TaskState`) are replaced by block reads through the HAL calling the same
        per-sector callback: written in Step 1, the first piece of the DVD access layer that replaces
        libcd later. Disc layout to start with: one PS1 disc image file on the DVD (PS1 sector → offset)
  - [x] libspu: `SpuMalloc`, `SpuSetIRQ`/`IRQAddr`/`IRQCallback`, `SpuSetNoiseVoice`,
        `SpuSetPitchLFOVoice`, `SpuSetReverbDepth`, `SpuGetAllKeysStatus`. The SPU interrupt is MGS's sound
        clock (voice 23 looping a silent block, 98.44 Hz): delivered IOP → SIF command → EE thread, with the
        PS1 thread switch `mts_isend` asks for (`tools/spu_irq_test`, PCSX2)
  - [ ] libcd: `CdReadyCallback`/`CdSyncCallback`/`CdReadCallback`, `CdGetSector`, `CdRead2`,
        `CdReady`, `CdFlush`, and the `St*` streaming ring
        **Interim only:** libcd emulation will later be replaced by DVD access functions (reading the
        game's files from the PS2 disc directly, not PS1 sectors). Keep it thin: just enough for
        `libfs/cdbios.c` to run, no investment in exact PS1 drive timing
  - [x] libpress: `DecDCTin`/`out`/`outSync`/`outCallback`/`Reset`, `DecDCTvlc2`/`DecDCTvlcBuild` (psyz's
        VLC, strdec's MDEC; checked against the game's DecDCTvlc2 and SH1's movies). 15-bit rounding
        unverified: check against DuckStation when MGS's movies play. The `St*` ring / `CdRead2` feeding
        them: MGS side (decision B)
  - [x] Overlays' library functions (inventory redone over all overlay maps): `MulRotMatrix0`,
        `RotMatrixZYX`, `RotMatrix_gte`, `SetPolyGT4`, `SetSprt`, `MargePrim`, `SetDefDrawEnv`, `BreakDraw`
  - [x] libgpu: `MoveImage`, `LoadImage2`, `DrawSyncCallback`, `GetTPage`, `SetSemiTrans`, `SetGraphDebug`
  - [x] libgte: `rsin`/`rcos`, `RotMatrix`, `RotMatrixYXZ`, `RotMatrixX/Y/Z`, the `*_gte` variants,
        `ReadRotMatrix`: bit-exact against MGS's linked code (`tools/libgte_test`)
  - [x] Misc: `SetMem`, `SetConf`, `GetGp`/`GetSp`, `rand`/`srand` (PS1's), `StopCallback`, `StopPAD`,
        `ChangeClearPAD`, `PClseek`, `LoadExec` (soft reset: stops for now)
  - [x] BIOS file calls for the memory card (`open`/`read`/... → `Port_Bu*` in `memcard/memcard.c`, as SH1);
        card detection works at boot in PCSX2. Saving and loading still to test once the game runs (needs the
        disc)
  - [x] `rank`'s PocketStation code (`mcx`): `SysEnqIntRP`/`SysDeqIntRP`, `ChangeClearRCnt` as no-ops.
        Its `FlushCache(void)` clashes with ps2sdk's `FlushCache(int)`: rename the call when recompiling `rank`
  - [ ] **PocketStation support: planned, low priority** (the stubs above only stand in until then). The PS2
        may have no library for it; check GitHub for a project that talks to a PocketStation from the PS2
        first, else write a custom implementation on low-level memory card port communication (SIO2)
  Full inventory (from `obj/asm.map`): `../psx-to-ps2-HAL/docs/Walkthrough.md`
- [x] **Threads for `mts`.** HAL `src/ps2/thread_ps2.c`: one EE thread per PS1 TCB, `ChangeTh` and
      VSync-interrupt switches, critical sections (`../psx-to-ps2-HAL/docs/Walkthrough.md`). Passes
      `tools/thread_test` in PCSX2. When `mts` is compiled: `(struct ToT *)0x100` → `Port_PsxToT()` under
      `MGS_PORT`. Still to try on a real PS2
- [x] psyz's libgte tests on the EE (`../psx-to-ps2-HAL/tools/psyz_tests`): 213 pass; the 12 failures are
      four libgte functions no game here uses. They found three software-GTE differences from the hardware
      (opcodes 0x00/0x1A, IR0 saturation flag), fixed. psyz's other tests need its platform layer: not run
      (MGS's uses of those libraries are tested against the game's own code instead). Still possible later:
      `psyz/psxgen` reference images for the GS backend

### Step 1 — PS2 build target

- [x] `build/build_ps2.py` (compile) and `build/link_ps2.py` (link, ELF and DVD image in `obj_ps2/`): ee-gcc +
      ps2sdk, `-DMGS_PORT`; does not touch the matching ninja file
- [x] Header shim: `port/include` shims MGS's `inline_n.h`/`inline_x.h` onto the HAL's GTE (stock PSY-Q 4.4
      headers otherwise)
- [x] Compile the main executable (168 files; 219 counted the VR and dev-only files by mistake) cleanly: `build/build_ps2.py`; dialect fixes under `MGS_PORT`
      logged in `Running Walkthrough.md`
- [x] Link with overlays stubbed out; boot to `main()` in PCSX2: `mts` and the game task start, the display
      comes up; `memcard_init` then waits on the stubbed libcard (24 generated stubs, listed by the link)

### Step 2 — Fixed addresses / shiftability

- [x] Triage of the `0x80xxxxxx` literals (2026-10-27, `tools/port/find_fixed_addresses.py`): 4585 in 156
      files. Buffers (main RAM from `MEM_ADDR` 0x80117000 up: heap, pack/load buffers, stack values) and
      the scratchpad: 102 scratchpad + 11 RAM, all wrapped. The rest (0x80010000-0x80116FFF) are addresses
      of code/data symbols, almost all in overlays (jump tables, `NEWCHARA` tables, `const int` dwords):
      they need real symbols when the overlays are linked in, so they go with Step 3
      (`find_fixed_addresses.py --symbols` lists them)
- [x] Single abstraction: `PSX_ADDR(literal)` (`source/include/psx_mem.h`, included by `psxdefs.h`): the
      literal in the matching build, the same offset in the HAL's `g_PsxRam`/`g_PsxScratch` in the port,
      kept an integer so casts, compares and `gte_*` arguments are unchanged. `SCRPAD_ADDR` and PSY-Q's
      `getScratchAddr` (shim `port/include/libetc.h`) go through it. `mts_get_bss_tail` (the overlay area,
      `StageCharacterEntries`) returns `PSX_ADDR(0x800C3208)`, the PS1's `_bss_orgend`, so it stays below the
      resident memory as on the PS1 (else every resident allocation reported "Resident Memory Over")
- [x] Scratchpad users routed (all `0x1F80xxxx` literals and macros)
- [x] `find_fixed_addresses.py` ported (`tools/port/`); reports nothing by default now
- [x] Matching build still passes (all hashes, and the VR executable)
- [ ] Shift test: pad an overlay and boot into its stage on PS1/emulator (needs Step 3)
- Note: `radiofacedraw.c`'s codec-screen noise read the PS1 executable's code at 0x80010000; through the
  arena it reads that part of `g_PsxRam` (probably zeros), so the noise may be blank. Check against
  DuckStation when the codec runs
- PCSX2 now (2026-10-27): loads the `init` stage, then `title`, no TLB misses; the EE stops responding
  ~13 s into the title stage (frame ~800 without direct logging), no message. Not the cdbios critical
  section (tested without it). Next to investigate; the title stage's overlay code can't run before Step 3

### Step 3 — Static linking of overlays

- [x] Static link (2026-10-27, `build/overlays_ps2.py`, as SH1): each overlay's objects (from
      `obj/linker_command_file_<ovl>_lhs.txt`) compiled like the main executable, `ld -r`-merged, every
      symbol made local except its CHARA table (`_StageCharacterEntries_<ovl>`). Shared objects (`enemy/*`,
      `takabe/*` in dozens of overlays) are a separate copy with separate data in each, as on the PS1. 59
      overlays link with no clashes; ELF ~8 MB. If RAM runs short later, they can go back to being loaded
- [x] Hook: `libfs/cdstage.c` (the `.bin` tag of a stage read) and `GM_LoadInitBin` call
      `Port_SetStage(id)` (`game/chara.c`): the stage's linked CHARA table by `GV_StrCode(name)`. The
      binary is still read into the arena's overlay area, unused. `GM_ResetChara` switches to an empty table
- [ ] Reset an overlay's `.data`/`.bss` when its stage loads again (SH1 needed it for a map loaded twice)
- [x] Policy: an overlay is linked in once it has no `INCLUDE_ASM` and no literal addresses of its own
      code/data (`tools/port/overlay_survey.py`); the link prints the rest. Left out now (20): brf, camera,
      d18a/d18ar, s03d, s07b, s08b/s08br, s11d, s11g, s15c, s19b/s19br (stubs); s05a, s07a, s11a, s11e,
      s11i (literal addresses: `NEWCHARA` tables, string/function pointer tables); rank, s14e (an
      object's source missing). Not in the matching build at all: s10a, s11b, s11h, s15a, s17a-s19a and
      some `r` variants
- [ ] First playable path: dock (s00a) → heliport (s01a) are both linked in
- [ ] Reduce the overlays' memory use by deduplicating: each overlay now has its own copy of every shared
      object's code and data (`enemy/*`, `takabe/*` in dozens of overlays). Share identical code (and
      read-only data) between overlays, keeping only the writable data per overlay
- Overlay GTE: `searchli.c`, `envmap3.c`, `libdg2.c`, `sub_efct.c` define their own GTE asm macros:
  translated by the HAL's `gen_gte_inline.py` (`port/include/gte_from_*.h`, included under `MGS_PORT`;
  `libdg2.c` after each of its four macro groups)
- Copy protection: `safechk.obj`'s `SafetyCheck` passes (`port/src/cdbios_ps2.c`), and
  `CdControl`/`CdControlB` report a closed drive
- To fix: `takabe/elevator.c`, `thing.c` test or set bit 31 of pointers (kseg0 on the PS1; EE pointers
  don't have it)
- PCSX2 now (2026-10-27): Konami logo → title (memory card check) → `opening`: the opening runs with its
  3D scene (~1400 prims a frame), 120 s with no crash and no TLB misses (frame dumps:
  `MGS_DUMP_FRAMES=1 build/link_ps2.py`). New stubs: movie streaming (`CdRead2`, `St*`, `CdReady`)
  and `select`'s host files (`PCcreat`/`PCwrite`)

### Step 3b — Unfinished overlay functions

About 100k instructions of `INCLUDE_ASM` remain in 12 overlays (largest: `brf` 21k, `s07b` 14k,
`rank` 12k, `s08b` 11k). Upstream is closing them steadily; don't decompile them all by hand first.

- [ ] Recompile the stubs with the SH1 recompiler (`../silent-hill-1-ps2-port/tools/port/recomp.py`,
      MIPS → C keeping delay slots, HI/LO and GTE). MGS's stub `.s` files are raw `dw` words with
      absolute addresses, so first rebuild relocations from the overlay's symbol addresses
- [ ] Pilot on one small overlay (`s11g` or `s03d`)
- [ ] Decompile by hand (non-matching C is enough) only where the recompiler fails or the port must
      change the code

### Step 4 — Software GTE

- [ ] Reuse the SH1 software GTE; check that the `gte_*` macros in the 30 MGS files map onto it
- [ ] Spot-compare transformed vertices against PS1 captures (pcsx-redux scripts in
      `build/pcsx-redux_scripts`)

### Step 5 — Graphics (libgpu → GS)

- [ ] `libdg` OT/prim submission through the HAL GS backend
- [ ] Check MGS-specific prim use: semi-transparency modes, texture windows, offscreen VRAM tricks
      (codec/radio screen, thermal and night-vision goggles, menu overlays)

### Step 6 — Pad, CD, memory card

- [~] `libfs` sector reads (disc 1 first; disc swap later). Done: `cdbios.c`'s task under `MGS_PORT` reads
      chunks of 16 sectors from `DISC1.BIN` (raw 2352-byte sectors, extracted from `ps1-original/*.chd`
      by `build/link_ps2.py`) through `port/src/cdbios_ps2.c` and hands each to the request's callback in
      a critical section. In PCSX2 the ISO9660 lookup finds every file at its right sector and STAGE.DIR's
      table is read. Still to do: disc swap (`DISC2.BIN` is on the image already), `CdControl`/`CdRead2`
      for movies and XA (`Port_CdHill` stub), `change`/`open`'s drive checks
      Found on the way: the game needs `-funsigned-char` (as PSY-Q's `ccpsx`; `build_ps2.py`), or byte
      reads through `char` sign-extend (the directory's file sizes came out negative)
- [ ] `memcard/` saves via the HAL memory card layer
- [~] Pad incl. vibration/DualShock analog: PadInitDirect buffers, polling thread, actuator setup (Step 1); buttons and vibration untested until the game runs past the disc

### Step 7 — Sound

- [ ] Run the `sd_*` driver against the HAL's SPU-on-SPU2 layer
- [ ] XA (codec voice) and STR/MDEC movies via the SH1 implementations

## Side tools (optional)

- [ ] PC debug build on psyz's SDL backend: debug game-code bugs (32-bit assumptions, NULL reads,
      fixed addresses) natively, separate from PS2 hardware issues. Not on the critical path

## Open questions

(none yet)
