# TAS Testing Plan

Use the TASVideos submission #5139 (`~/Downloads/submission5139/metalgearsolidintegral-allbosses-theenglishman.bk2`)
as a long, scripted regression test: replay its input in the port and check the game state against the PS1 game
replaying the same movie.

## What the movie is

- BizHawk movie (`.bk2`, a zip): `Header.txt`, `SyncSettings.json`, `Input Log.txt`, `MovieSaveRam.bin`.
- Made with BizHawk 1.11.4 (movie format v2.0.0), Octoshock core, Japanese BIOS (SHA-1 in `Header.txt`),
  game `mgsintegral`. This is the same disc the port is built from (SLPM-86247 on the memory card).
- 313,202 frames, one line per video frame (about 87 minutes at 59.94 Hz). 61,552 rerecords.
- Columns per frame: disc select/open/close/reset, then P1 and P2 each with 4 analog bytes and 17 buttons
  (Up..R3, MODE). Both ports are DualShocks (`Devices8: [3,...,3,...]`). Both memory cards are inserted.
- The first press is at frame 1,485. The analog sticks are off-centre on 188,916 frames, so analog input matters.
  P2 is pressed on 3,803 frames, probably the Psycho Mantis controller-port switch.
- Disc 1 → disc 2 swap: tray open at frame 181,883, disc 2 closed at 181,906.
- `StartsFromSaveRam True`: the movie starts with a memory card holding an Integral save. Per the TASVideos
  page (saved in `~/Downloads`), the run uses the save and a code to unlock Extreme difficulty (Normal Round),
  aiming for BIGBOSS rank. The port needs the memory card and that unlock before the first stage diverges for good.
- Published; verified on BizHawk 1.11.4 with both discs loaded as a multi-disc bundle (an XML game file or `.m3u`
  listing the disc 1 and disc 2 `.cue` files). BizHawk's load times are close to the console's.

## Why a plain replay won't work

A TAS only plays back correctly on an emulator that matches the original's timing exactly: lag frames, CD seek
times and the RNG all have to match. The port won't match Octoshock's timing per vertical blank (CD reads, load
times and slow frames all differ). So we don't feed the inputs by video frame. We
1. replay the movie in the emulator it was made with, and record what the **game** read from the pad on each
   **game frame** (one pass of the main loop), along with the game state;
2. feed the port the same pad values on the same game frames, counted from each stage's load;
3. compare the port's state to that trace on every game frame and report where they first differ.

The port already has the pieces for this from the DuckStation comparison: a clock locked to the PS1's
(game loops counted from a load's end, `GV_Clock` parity matched) and scripted pad input
(`port/src/pad_script.c`).

## Phase 1: reference replay (PS1 emulator)

- [x] BizHawk 1.11.4 downloaded from GitHub to `~/emu/bizhawk-1.11.4` (2026-10-29). `EmuHawk.exe` (.NET 4) and
      `octoshock.dll` are both 32-bit, so it needs 32-bit Wine (`wine32:i386`). wibo doesn't run .NET programs.
      Then install .NET 4.x and the VC++ runtimes with winetricks.
- [x] Runs under 32-bit Wine with wine-mono (no Microsoft .NET needed). `~/emu/tas/run_bizhawk.sh` starts it with
      the movie and both discs (`mgs.xml`, cue/bin extracted from the CHDs with `chdman` to `~/emu/mgs-integral/`)
      and reapplies the settings BizHawk overwrites on exit. Direct3D display fails under Wine (shader compile
      error), so OpenGL; sound off; frame skip 7: about 80 fps. 1.11.4 has no `--lua` option; the script
      sets the Lua console's own auto-open and the recent-script auto-load, so the run needs no clicks (tested to
      frame 7,200). A watchdog stops a stalled run (log unchanged 90 s) and prints OK/FAILED.
- [x] Unattended full run (2026-10-30): `client.exit()` closes BizHawk at frame 313,202 and the script prints `OK`.
- [x] Get the Japanese BIOS matching `PSX_Firmware_J` (`ps-10j.bin`, v1.0 J, set explicitly in the config;
      not found automatically) and point BizHawk at the Integral disc images
      (disc 2 is needed for the second half).
- [x] Full replay in sync (2026-10-29, `synccheck.lua`, log in `~/emu/tas/synccheck_full_run1.log`): 118 stage
      visits, disc change (`change` stage) at frame 181,800, credits (`roll`) from frame 290,400 to the end.
- [ ] Find out what the save on the memory card is used for (watch for a load at the title screen or a check
      during the Mantis fight).

## Phase 2: per-game-frame trace (BizHawk Lua)

- [x] `tools/port/tas/trace.lua` (2026-10-30), started by `tools/port/tas/run_bizhawk.sh tools/port/tas/trace.lua`
      (no clicks; the scripts are in the repo, the movie, discs and logs in `~/emu`). One text line each time
      `GV_Time` changes, to `~/emu/tas/trace.log`: movie frame, `GV_Time`, `GV_Clock`, `GV_PassageTime`,
      `GM_GameStatus`, the `rand` seed (`0x800C1530`, read from `rand`'s code), stage name, `GV_PadData[0..1]`
      (what the game read that loop), the raw mts pads `pad_800C14E0[0..1]`, `GM_PlayerPosition`,
      `GM_AlertMode`, `GM_LoadRequest`, `DG_UnDrawFrameCount`, and `linkvarbuf` (96 shorts: the save state).
      Addresses from `obj/asm.map`. Costs almost no speed (about 73 fps).
- [x] Deterministic: two runs gave identical lines (3,173 lines compared).
- [x] The intro (`d00a`) steps every vertical blank (`GV_PassageTime` 1), gameplay (`s00a`) every 2.
      `linkvarbuf[1]` (`GM_GameLevel`) is 3 (Extreme) from the start: the memory card save's unlock.
- [x] Full reference trace (2026-10-30): `tas/reference/trace.log.xz`, 163,839 loops (restarted for each new field: the replay tables need all of them)
- [x] The memory card save (2026-10-30): it sets no game state. The title only reads the card's file names
      (`onoda/open/open.c`): `BISLPM-86247G:E0pBAA` on card 1 (clear flag 2) unlocks Extreme, which the TAS
      picks at frame 1,582. Faked with fixed test cards in the HAL (`src/ps2/memcard_fixed.c`,
      `SH_PORT_MC_FIXED`): `MGS_MC_IMAGE=~/emu/tas/MovieSaveRam.bin python3 build/link_ps2.py`. PCSX2: `This
      Is Rank 2`, `demo_rank = 2`, as on the PS1
- [ ] Split by stage visit for Phase 3/4
- [ ] Optional: a hash of the active actor list, if the fields above don't find a divergence early enough

## Phase 3: replay in the port

Build (all files from `tools/port/tas/trace_to_pads.py ~/emu/tas/trace.log`):
`MGS_MC_IMAGE=~/emu/tas/MovieSaveRam.bin MGS_TAS_PADS=~/emu/tas/pads.bin MGS_TAS_RAW=~/emu/tas/raw.bin
MGS_TAS_TIME=~/emu/tas/time.bin python3 build/link_ps2.py`; run in PCSX2; then
`tools/port/tas/compare_trace.py obj_ps2/tas_trace.log --from 315`.

- [x] Replay by game loop (`GV_Time`), `port/src/tas_replay.c` (2026-10-30): the port writes the PS1's
      `GV_PadData[0..3]` at the end of `GV_UpdatePadSystem` (exact: the reference's own result), and the raw mts
      pads and pad init states at the end of `mts_pad.c`'s `do_control` (for `cancel.c`, `gamed.c`, `movie.c` and
      `mts_get_pad_vibration_type`: Mantis, and `GM_CONFIG_VIBRATION_OFF`, which BizHawk's pad sets).
- [x] Port trace to `host:tas_trace.log` in the reference's format, from `gvd.c`'s `Act` before `GV_Time++`.
- [x] Timing follows the PS1's: the game loop runs during loads, and they take a different number of loops in
      the port, so at each load end `GV_Time`, `GV_Clock` and `GV_PassageTime` become the PS1's at its matching
      load end; `GV_PassageTime` is the PS1's every loop; streams get the PS1's tick (`FS_StreamGetTick`, from
      `mts_time` and `stream.c`'s statics: BizHawk 1.11.4 has no execute callbacks for PSX) and start in its
      loop; the rand seed becomes the PS1's at each load start and end (the title runs a different number of
      loops before New Game). Tried first: holding the load's end until the PS1's loop (loads aren't always
      faster in the port).
- [x] First run (dock): identical from New Game (loop 315) to loop 1015 except the items below.
- [ ] Streams: the port's `St*` functions are stubbed, so the dock's opening voice-over/subtitle stream ends at
      once (`FS_StreamGetData` gets no packets; first seen at loop 572 before the timing work) and the intro's
      demo stream differs (`DG_UnDrawFrameCount` at 497, the seed at 808). A port gap (Step 6), not the harness.
- [x] Sample points (2026-10-30): a loop runs `gvd.c`'s `Act` (`GV_Time`, clock, passage time), `dgd.c`'s wait
      for the vertical blank and pad update, then the actors. BizHawk's line N is taken during that wait:
      loop N's timing, loop N-1's game state, and loop N-1's pads; loop N's pads are on line N+1 (with line N's,
      the title goes to New Game a loop late). The port samples at the end of `gvd.c`'s `Act` to match.
- [x] The port's trace fields 18-19 (with `trace_debug.lua`, which stops at frame 3,300 and adds them):
      `GM_PlayerStatus` and Snake's `CONTROL` (compared without its pointers).
- [x] The tables are read from `host:` at startup (`tas_*.bin` next to the disc image), not linked in:
      embedded, they pushed `.bss` past 16 MB, and the HAL's ordering tables keep 24-bit links (TLB misses in
      `DrawOTagImpl` at boot). `port/linkfile` now asserts `_end_bss <= 0x1000000`. Placing them after `.bss`
      fails: ps2sdk's `crt0` zeroes up to `_end` and starts the heap there.
- [ ] Loop 1012 (0:00:48.50 in the movie): Snake turns a loop early in the port. Snake's work (`trace_debug.lua`
      field 21: his state function, resolved through each side's symbols, and `field_A38_local_data`) is identical
      up to loop 1011: both in `sna_anim_idle_8005275C` frame 1 with the countdown at 0, and the port's
      `sna_fn_80052E58` starts the turn in loop 1011, the PS1's in 1012. Snake reads `GV_PadData` directly, so in
      loop 1011 the PS1's still had dir -1: the pads of the line N, not N+1, which the title and the intro's end
      contradict. Not settled whether BizHawk's sample point moves (then the harness feeds the dock's pads a
      loop early) or the port differs. Tried: a rule from the game task's wait (`mts_tasks_800C0C30[3].intr`
      last/target, now field 18 of both traces): the dock matched to loop 1040, but the intro's long loading
      loops broke (other waits than `dgd.c`'s), so the N+1 rule stays. BizHawk 1.11.4's execute and write
      callbacks don't fire for PSX (registered, no hits). Next: the exact moment of `GV_UpdatePadSystem` in a few
      dock and title loops from DuckStation's GDB (a breakpoint on its return, a few dozen stops).
- [ ] Load end 4 (after the dock's alert): the port's at loop 5635, the PS1's 5457: after the divergence above.

## Phase 4: segments, so one bug doesn't stop the whole run

- [ ] Run each stage visit as its own segment: boot the port straight into the stage with the game state the
      reference had when it loaded (the save block from Phase 2, plus the RNG seed). A desync then only fails that
      segment.
- [ ] Report per segment: passed, or the first diverging game frame and field. Keep a list of known divergences
      (with the bug they come from) so the report shows only new ones.
- [ ] Rerun the whole movie with no state injection now and then, to catch bugs that carry between stages.

## Phase 5: grow the test with the port

- [ ] First target, available now: from boot to the end of the heliport (s00a, s01a). Expect divergences on the
      way to the dock (intro, New Game menu); fix or note each one.
- [ ] Add segments as overlays get linked in (Step 4/5 of the Planning Doc).
- [x] Memory card: fixed test cards from the movie's image (see Phase 2).
- [ ] Disc 2: segments after movie frame 181,883 wait on disc swap support.
- [ ] Automate: one command rebuilds, runs the segments in PCSX2 (software GS, stall rule = crash), and prints
      the per-segment report. Collect any "TLB Miss" PCs from the run as failures.
- [ ] Optional: the same segments on real hardware through `ps2_ctl.py`, for timing-related bugs.

## Risks

- **The movie may not sync on any build we can run here.** Then Phase 2 can't use BizHawk, and the
  trace would have to come from DuckStation by setting the pad through the GDB stub, which the per-frame stop rule
  forbids. In that case, record a game-frame trace once, rarely stopping (e.g. at stage loads only), and accept
  coarser checks.
- **The game's clock.** MGS steps its logic by the vertical blanks that passed (`GV_Clock`). If the port's
  frame pacing differs, the game frames themselves differ. Use the PS1-timing lock from the opening comparison
  for TAS runs.
- **The RNG and uninitialised memory.** The PS1 doesn't zero memory the way the port does. Differences may show
  as RNG drift; compare the seed every frame so the cause is found at the first frame it differs.
- **Analog dead zones / DualShock mode switch.** The movie expects the controller already in analog mode
  (`MODE` column); the port's pad layer must match the result the game sees, not the raw protocol.
