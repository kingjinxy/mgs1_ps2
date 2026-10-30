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
      once (`FS_StreamGetData` gets no packets; first seen at loop 572 before the timing work). A port gap (Step
      6), not the harness. The intro's demo stream now matches (stream timing, below).
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
      callbacks don't fire for PSX (registered, no hits). DuckStation (`tools/port/gdb/snake_turn_ps1.py`, a
      press written at loop L's pad update): the PS1's Snake sets his turn in loop L, as the port's does. So the
      port is right and the harness gave the dock's pads a loop early: BizHawk's line N holds loop N's pads in
      the dock but loop N-1's at the title. A rule from the wait pattern (last = mts-1, target = mts+1: loop
      N's) fixed the dock (Snake equal to loop 1040) but the intro's skip press (line 517, same pattern) then
      came a loop late: `target` is set by every `mts_wait_vbl` call, and a loop makes more than `dgd.c`'s.
- [ ] Load end 4 (after the dock's alert): the port's at loop 5635, the PS1's 5457: after the divergence above.

## Control run in PCSX-Redux

- [x] `tools/port/tas/redux_replay.lua` (2026-10-30): the PS1 game in PCSX-Redux (Linux build from distrib.app,
      `~/emu/pcsx-redux`; the user approved the site) under the port's harness, from the same tables, with execute
      breakpoints at the port's hooks: `GV_UpdatePadSystem`'s return (pads), `do_control`'s (raw pads), the
      `FS_StreamGetTick` return (`v0`), `NewLoader` and the loader's `Die` (seed), `gvd.c`'s `Act` return (realign,
      passage time, seed, the trace). No stream start gate (it needs a code patch). About 50 loops a second:
      ```
      cd ~/emu/pcsx-redux && ./PCSX-Redux-HEAD-x86_64.AppImage -no-ui -debugger -run -noupdate -safe -interpreter \
        -fastboot -bios=<ps-10j.bin> -memcard1=card1.mcd -memcard2=card2.mcd -iso=disc1.cue \
        -dofile=tools/port/tas/redux_replay.lua     # TAS_LAST (loop to stop at), TAS_DIR, TAS_OUT
      ```
      `card1.mcd` is the first 128 KB of the movie's `MovieSaveRam.bin` (Redux saves the cards on exit: recreate
      them). Failed first: the breakpoint handles in a local table (Redux drops a breakpoint when its handle is
      garbage-collected), the BIOS shell without `-fastboot`.
- [x] Result (dock, to loop 1,300): the control run (real PS1 code) shows Snake's turn a loop early at 1012
      like the port, so that's the harness's pad timing; port against the control run: Snake identical to loop
      1,300. Port differences left: `DG_UnDrawFrameCount` at loop 497 (the control: 504; the intro's demo stream),
      the seed at 809, `GM_GameStatus` bit `0x40` at 1,164.
- [x] Pad timing settled (2026-10-30): `GV_LastTickCount` (now in field 18, `last:target:tick`) equals the line's
      `mts_time` on every line, so every line is taken before its loop's pad update and the N+1 rule holds. Snake's
      loop-1012 turn came from the codec's end: in loop 1011 `dgd.c`'s pad update ran with `STATE_PADRELEASE`
      (no direction for Snake), then the codec script cleared it and updated the pads again; writing the recorded
      final `GV_PadData` at both gave Snake the stick a call early. Now the harness rebuilds mts's raw pads at
      `GV_UpdatePadSystem`'s entry from the record (`[2]/[3].status` buttons, the d-pad bits cleared in analog
      mode; `[0]/[1]` sticks) and the game computes `GV_PadData`: identical to BizHawk's on every loop (control
      run). Snake now matches BizHawk to loop 1,078 in the control run and the port; port against control: Snake
      identical. Redux's own phase measurement (pad update in the same video frame as `GV_Time++`): "later"
      everywhere, but its CPU timing isn't BizHawk's.
- [x] Stream timing (2026-10-30): the intro's demo packet (`DG_UnDrawFrameCount = 3`, `strctrl.c` type 5) came
      10 loops early in the control run. Found:
      - the start gate was wrong: `STATE_VOX_STREAM` is set when `strctrl.c`'s actor is made (PS1 loop 489), but
        the stream's clock starts (`FS_StreamTickStart`) at 512. The tables now count the PS1's starts
        (`fs_stream_last_time` from -1, `FS_StreamTaskStart`'s value, to a vertical blank with
        `fs_stream_next_time` 0), and a start waits while ours have caught up (port: `Port_TasTickStart`; Redux:
        a breakpoint at `FS_StreamTickStart` and a jump over case 2);
      - the tick table held the clock after the loop's last call: in the audio packet's loop
        `FS_StreamSoundMode` resets it, and the last loop of a stream has the reset (`FS_StreamTaskStart`); both
        now take the clock before the loop. `NO_TICK` replays as `mts_time + 1` (the function with
        `fs_stream_last_time` -1), not the emulator's own value;
      - new trace field 19: `fs_stream_bottom`'s offset in the stream heap (the disc data in so far). Redux
        stops `FS_StreamGetData` at the PS1's bottom (`v1` at the `beq` after its load); here the PS1 had the
        packet's data 10 loops before using it, so the start and tick were what mattered.
      Mistakes on the way: disassembling `_mgsi.exe` with base 0x7FFFF800 (the PS-X header is 0x800 bytes: the
      base is 0x8000F800), which put the first gate on a gameover function; setting `v1` at the load's delay
      slot (still the old value).
      Result (dock, to 1,300): the control run matches BizHawk except the codec below; Snake's `CONTROL.vecs` at
      1,079 went too. The port: Snake to 1,781, the alert to 2,388.
- [ ] The intro's codec (Campbell, from loop 816) reaches its call state (`radio.c` case 5: `rand()` every 4th
      loop) in the control run at 820 and the port at 808; on the PS1 the skip at 823 came first. The codec
      rings until `FS_LoadFileSync` (its radio data) is done. Trace field 20 is `cdbios_task.remaining * 4`;
      gating `FS_LoadFileSync` on it (Redux, opt-in `TAS_FILE_GATE`) moved the `rand()` to 840 and lost the
      skip: the PS1's CD task then was the ended stream's endless read (0x7FFF0000 to come), so its codec read
      waited behind it. Not modelled yet. The seed is resynced at the load at 921.
- [x] Stop at the first desync (2026-10-30): `tools/port/tas/run_port.py` links, runs PCSX2, follows the trace
      live and closes PCSX2 at the first differing loop (`--ignore` for known ones, still reported). First use:
      45 s, and it showed the seed differing again at loop 930, after the resync at 921 (the whole-run compare
      reports only each field's first difference, so it was hidden behind 809).
- [ ] Port only: the seed at 930, `STATE_CUT_IN` at 1,164.

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
