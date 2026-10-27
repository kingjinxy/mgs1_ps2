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
  - [ ] BIOS file calls for the memory card (`open`/`read`/... → `Port_Bu*` on the game side, as SH1):
        game code, so in Step 1 with the port build
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

- [ ] `build/build_ps2.py` (or a `--ps2` mode for `build.py`): ee-gcc + ps2sdk, `-DMGS_PORT`, output
      ELF; does not touch the matching ninja file
- [ ] Header shim so `source/include` resolves PSY-Q headers to the HAL's
- [ ] Compile `main`, `libgv`, `libdg`, `libgcl`, `libfs`, `libhzd` cleanly; log compiler-dialect
      fixes (old-GCC-isms written to match `cc1psx`) in the walkthrough
- [ ] Link with overlays stubbed out; boot to `main()` in PCSX2

### Step 2 — Fixed addresses / shiftability

- [ ] Triage the 156 files with `0x80xxxxxx` literals: real addresses vs constants
- [ ] Single abstraction for fixed addresses (`PSX_RAM_ADDR`/`PSX_SCRATCH` as in SH1's `psx_mem.h`)
- [ ] Route the 8 scratchpad users through `PSX_SCRATCH`
- [ ] Port `find_fixed_addresses.py` and run it as a regression check
- [ ] Matching build still passes (all hashes)
- [ ] Shift test: pad an overlay and boot into its stage on PS1/emulator

### Step 3 — Static linking of overlays

- [ ] Find how stage overlays are loaded and entered (`libfs` + stage loader in `game/`) and add one
      port hook: skip the read, reset that overlay's `.data`/`.bss`, and activate it via a dispatch
      table
- [ ] Namespace per-stage symbols that clash across overlays
- [ ] Choose a first playable path that avoids stub-heavy overlays (e.g. dock → heliport)
- [ ] Policy for remaining `INCLUDE_ASM`: an overlay is excluded from the port link until it has no
      stubs; track the list here

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

- [ ] `libfs` sector reads via the HAL (disc 1 first; disc swap later)
- [ ] `memcard/` saves via the HAL memory card layer
- [ ] Pad incl. vibration/DualShock analog

### Step 7 — Sound

- [ ] Run the `sd_*` driver against the HAL's SPU-on-SPU2 layer
- [ ] XA (codec voice) and STR/MDEC movies via the SH1 implementations

## Side tools (optional)

- [ ] PC debug build on psyz's SDL backend: debug game-code bugs (32-bit assumptions, NULL reads,
      fixed addresses) natively, separate from PS2 hardware issues. Not on the critical path

## Open questions

(none yet)
