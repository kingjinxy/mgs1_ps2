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
- [x] Seed at loop 930 (0:00:45.76): a rat (`mouse.c`) changed state a loop early. The s00a load at 917
      (0:00:44.86) doesn't go through `loader.c`, so the seed wasn't resynced at its start, and the rats drew their
      segment lengths from the seed the codec had drifted. The seed is now also resynced when `GM_LoadRequest` is
      set (port and Redux).
- [x] Play time at loop 490 (0:00:33.95), shown at 1,001 (0:00:48.13): `gTotalFrameTime` adds `GV_PassageTime`
      on every loop, load loops too, and the port's loads take fewer loops. Trace field 21 records it (it can't be
      rebuilt from the passage times); at each load end it and `GM_PlayTimeHours/Seconds` become the PS1's.
- [x] `STATE_CUT_IN` at loop 1,164 (0:00:53.57), a port bug: with no camera (`i == -1`) `camera.c` reads
      `GM_CameraList[-1].trg.pad`, which on the PS1 is the high half of `gUnkCameraStruct2_800B76F0.type` (0) and
      in the port the stream buffer before the list. `MGS_PORT` reads the PS1's bytes.
- [x] Sticks at loop 2,462 (0:01:36.88): a held d-pad in analog mode clears `GV_PadData`'s analog but the game
      still copies the sticks; the rebuild now writes them whenever the raw pad (its recorded mode) is analog.
- [x] Snake's position at loop 4,221 (0:02:35.57), a port bug: the wall knock at 3,988 found no wall, so no noise,
      so a guard didn't turn at 3,997 and wasn't in the punch's homing range at 4,219. `sna_8004F544` passed
      `&vec1` to `sna_line_check`, which reads `line[1]` (`vec2`, next to it only on PSY-Q's stack); now an array
      under `MGS_PORT`, as in three more callers.
- [x] Screenshots at each desync (`run_port.py`, `tas/shots/loop_<T>.png`: PS1 from the Redux control run | port |
      difference over 24).
- [x] `GV_PadData` at loop 5,110 (0:03:05.37), the harness: `STATE_PADRELEASE` zeroes `GV_PadData[2]/[3]`, which
      the tables took the controller from, and a second update in the loop (`PadCmd`) reports the release. Where the
      game zeroed them, the buttons now come from mts's raw pads (`trace_to_pads.py`). (Its screenshot differs over
      most of the top half: not looked into.)
- [x] `DG_UnDrawFrameCount` at loop 5,751 (0:03:21.53, `d01a`), the harness: after `FS_StreamSoundMode`,
      `strctrl.c` asks for the tick again in the loop and the PS1 got -1; the harness now returns -1 then.
- [x] rand seed at loop 5,809 (0:03:24.39, `d01a`), the port: a codec call's file read (trace field 20) runs from
      5,796 to 5,817 on the PS1 and is in earlier in the port, so the call state's `rand()` comes early (its
      screenshot: the portraits shown, the PS1's still black). Tried: `FS_LoadFileSync` returning the PS1's bytes
      left (under 0x7FFF0000) in every loop; it broke the s00a load at loop 917 (0:00:44.89). Then the gate only in
      radiomes.c's codec poll (`menu_radio_codec_helper_helper9_80047FF4`), only while the PS1's count went down
      (flat counts are stale: 2,048 at loops 779 to 787, 0x7FFEF000 at 502 to 763 held the intro call): in sync
      to 5,808 again, 5,809 unchanged. A poll log shows why: the port's codec read runs at loops 5,775 to 5,782
      (0:03:22.3), the PS1's at 5,795 to 5,816, so the port *requests* the file about 20 loops early; the read's
      speed isn't it. To find: what the PS1 waited on before the request (the call's start, a stream or a seek).
      Not the stream (Redux: `fs_stream_task_state` 0 from loop 5,760): the PS1's drive. Fixed for the whole class:
      TAS builds pace file reads (no callback) to the PS1's 2x drive, 2.5 sectors a vertical blank plus a seek of
      1 + 0.075 * sqrt(distance) vertical blanks (`port/src/cdbios_ps2.c`; fitted to the codec reads, a little
      short: the harness waits for an early port, not a late one). Pacing streams and stage loads too broke loop
      917 (0:00:44.89; streams follow the PS1's clock already, loads end at its loop); a fixed 10-vertical-blank
      seek made the intro call late, also at 917. The port trace now has the file read's bytes left (field 20,
      not compared), and lines past the PS1's load end while the port still loads are left out (the loop number
      is the PS1's at the load's end).
- [x] rand seed at loop 6,277 (0:03:37.57, `s01a`), the port: the drive model's seeks. BizHawk logs of the codec's
      state (a throwaway Lua like trace_debug.lua: `Work` 0x800BD360, state at +0x210; the call's chara struct
      pointer at 0x800ABB38) gave the PS1's timeline per call: the face read's end starts a 16-loop countdown to the
      call's state 5, which draws 2 `rand()` every 4th loop, so one loop off moves the draws. The Redux control run
      is no reference here (its call reached state 5 at 5,825; the PS1 at 5,834). Fixes: a read is charged only for
      the sectors it wants, not the whole 16-sector chunk (the 2-sector RADIO.DAT read was charged 16); the seek is
      a table over sqrt(distance) (0 and 38: 0 blanks, 97: 20.6, 347: 38.6), fitted to the three calls' face read
      starts and ends; a contiguous chunk goes on from where the last was due (up to 2 blanks back).
- [x] rand seed at loop 6,497 (0:03:46.01, `s01a`), the port: the second call's RADIO.DAT read took 2 loops, the
      PS1's 14. The PS1's drive had gone to the last call's voice stream; the port's held stream read (below) never
      moved the modelled head. A held read now does (`MgsCd_Head`).
      Also from here: a stream's first read is held while the PS1's stream heap is empty (time.bin's bottom 0;
      `Port_TasStreamHold`): the PS1's codec voice at 5,827 had no data until 5,950. The held read looks like one in
      progress (`fs_stream_read` set, task state -1), and `FS_StreamSync` starts it.
- [x] `GM_GameStatus` 0x1000 and `DG_UnDrawFrameCount` at loop 6,663 (0:03:52.10, `s01a`), a cutscene's demo
      stream: its packet is in a loop early. Stream sectors now reach the game only as far as the PS1's had by the
      loop (time.bin's file read bytes left; `Port_TasStreamAhead`), and the bytes match the PS1's at each loop's
      end, but a packet is used once its last sector is in, which falls within a loop. Tried: the last loop's
      value (broke 5,481), the midpoint (broke 5,753), interpolating over the PS1's vertical blanks of the loop
      (mts_time added to time.bin; 6,663 either way). Screenshot black on both.
      Fixed with a per-frame BizHawk log (a throwaway Lua reading memory each frame): the drive brings 6,144 and
      4,096 bytes by turns each vertical blank, and the packet completed on the blank that begins loop 6,663, used
      by 6,663. The gate is now the loop's start value (the last loop's record) less 5,120 bytes a vertical blank
      since the loop began (`s_LoopTick`, at Port_TasTrace), down to the loop's end value.
- [x] `GM_GameStatus` 0x60000000 at loop 6,667 (0:03:52.25, `s01a`), the harness: `pad_demo.c` sets
      `STATE_PADDEMO | STATE_NOSLOW` at `DG_UnDrawFrameCount` 1, then stops at once if `mts_read_pad(1)` has the
      cross (the TAS skipping). The PS1 still held it in loop 6,666; the port's raw pads had it let go, because
      `Port_TasPads` rewrites them from the pad record, which is the next trace line's. Now `Port_TasPadsDone`, at
      the end of `GV_UpdatePadSystem`, puts the buttons back to `Port_TasRawPads`'s (the PS1's at the loop's
      vertical blank) for the code that reads them directly later in the loop.
- [x] PCSX2 crash after loop 6,732 (0:03:55.00, `s01a`, the first gameplay after the cutscene): TLB miss in
      `DG_TransChanl`, once loading `obj->model` from a `DG_OBJS` base of 0x8407ee4, once `lw v1, 8(sp)` with sp
      0x8410e44, then a jump to 0xff70fee6. Both values look like a valid address with 0x08000000 set, but sp isn't
      near the task stacks (`mts_port_stacks` 0x6715c8, 32 KB each). The draw queue's entries and their models
      were all in RAM (a debug check with the queuer's return address). Before it: "command.c: Where Is Snake
      ????" three times (`s00a_command`: Snake's zone 0xFF; only prints). To try: a sentinel on the game task's
      saved context and stack (SH1's gte.c approach), the HAL's ISR thread switch (`Port_ThreadIsrSwitch`).
      Found, a port bug: `takabe/lit_mdl.c`'s `litmdl_dg_def` initializes the zero-length `DG_DEF.models[]`, which
      GCC drops ("excess elements in array initializer"; PSY-Q's kept it), so the global was the 32-byte header and
      the actor's `memcpy` of header and model took the next data as its model: 2,509,024 vertices. Once visible
      (loop 6,741; the trace flushes every 64 loops, so it showed 6,732), `DG_TransVertices` wrote them through
      the scratchpad (`g_PsxScratch`, ordinary memory at 0x91b780) up through the game thread's stack. Found by
      printing each object `DG_TransChanl` starts on, then who made the one with the bad model (`DG_MakeObjs`'s
      caller). Fixed with a header-and-model struct under `MGS_PORT`; the only file with that warning.
- [x] rand seed at loop 7,597 (0:04:21.14, `s02a`). Its screenshot's PS1 side (the Redux control run) shows GAME OVER
      and the port a codec call: Redux has drifted from the PS1 by here, so that side is no reference.
      A codec call whose face read the PS1 started 19 vertical blanks after its request, for a 2,287-sector seek
      (BizHawk per frame: `cdbios_task` at 0x800B4E58), where `d01a`'s took about 4: the seek model can't know.
      File reads now follow the trace like streams: `Port_TasFileStart` (in `CDBIOS_ReadRequest`) finds the PS1's
      read of the same size (time.bin's bytes left becoming it, from 3 loops back to 60 on) and
      `Port_TasFileAhead` holds sectors past the PS1's progress, per vertical blank; the model is only for reads
      the trace doesn't show (none in the run so far).
- [x] `GM_GameStatus` and `GV_PadData` at loop 9,253 (0:05:16.50, `s02a`), the harness: the circle press at the
      elevator. Where the pads were zeroed, trace_to_pads.py rebuilt [2]/[3] from line t+1's raw pads (`n[8]`);
      the loop read line t's (`f[8]`, as raw.bin), and line t+1 had the circle let go. Found with a BizHawk
      screenshot (`client.screenshot`) and the elevator panel's state read from PS1 memory (found by its actor's
      filename string): the panel wasn't it, the raw pads were. Loop 5,110 still passes.
- [x] `GV_PadData` at loop 9,633 (0:05:25.68, `s03a`), the harness: the load's end. The port's faster load
      reaches it at its own loop 9,451, realigned to the PS1's 9,633, with its own last pads. Now loads.bin
      (trace_to_pads.py: each PS1 load end's GV_PadData as recorded) sets GV_PadData and pad.c's last status
      (`dword_800AB950`/`954`, behind press and release) at the realign, and from the loader's end
      (`GM_LoadComplete` -1) the port gets the pads of the PS1's last loop of the load (Snake's walk started
      there with down held; anim frame `field_9BC` was a loop ahead). pads.bin's own records won't do: their
      [2]/[3] can be rebuilt (loop 490).
- [x] rand seed at loop 11,444 (0:06:19.70, `s03d`). Screenshot no use: Redux is at the title screen by here, the
      port's dump black (run_port.py now waits 3 s before closing PCSX2 when dumping: the first was cut).
      Not a desync: `s03d` isn't in the port. Its actors at loop 11,445, PS1 (BizHawk, walking `ActorList`
      0x800ACC18) against port: the port lacks `cinema.c`, `asioto.c`, `evpanel.c`, `uji.c` x2, `lamp.c` x4,
      `wall.c` x2, `intr_cam.c` (the PS1's cutscene draws rand every loop). `overlays_ps2.py` leaves `s03d` out
      for 21 INCLUDE_ASM: the guards, `overlays/s03d/animal/zako/zako.c` (18) and `zakocom.c` (3); upstream has
      them as assembly too. Being decompiled (the user's choice over stubs): `tools/port/match_asm_funcs.py s03d`
      ranks decompiled functions by call sequence (12 of the 21 have a counterpart at 0.9 or better in
      `zako11a`/`zako11e`/`zako11f`/`enemy`), `tools/port/fdiff.py s03d <func>` shows the differing instructions
      of one against `build/s03d.matching.bin`. `s03d`'s `Work` is its own layout (target pointer at 0x8FC and a
      TARGET at 0x900, where zako11a has the pointer at 0x900), so fields are mapped from the assembly.
      Decompiled so far, matching: zako.c `s03d_800CF194`, `800CEE3C`, `800CF68C`, `800CFB04`, `800CE12C`, `800CDF94`,
      `800CE720`, `800CE318`, `800CCE3C`, `800D09D8`, `800CEB38`, `800D041C`, `800CDB5C`, `800CD75C`, `800D0C90` with
      the four after it in its .s; zakocom.c `800D46F8`, `800D4EAC` with its Act and Die, `800D55C8` with the
      commander's constructor (zakocom.c is complete). For the port only (`#ifdef MGS_PORT`; the matching build keeps
      the INCLUDE_ASM, and `overlay_survey.py` skips that `#else`), C that differs from the PS1 in register choice
      alone: `800D1054` with three more senses, `800D14AC`. Also matching: `800CD1C4` (GetResources) and the guard's
      constructor; `Work` is 0xBA4 bytes (was padded to 0xC00), `PARAM.fAF9`/`fAFA` are signed. No INCLUDE_ASM left;
      next, the literal addresses (7 by the survey, the stage table's among them).
      What it took: jump tables come out of the rodata files (`overlay2.c`, zakocom.c's own block) with any constants
      after them moved below the function, so the order holds; inline helpers (`SetAction`, `SetMode`, ...) for the
      PS1's scheduling; zako11a's empty `for (i = 0; i < 0; i++)` loop in the init for its block layout; a struct
      cast for the top command pair; declaration order for stack slots. `PARAM`'s 0xB16 is the faint (what
      `Zako_800CCCF4` passes to `GM_SetPowerTarget`), not `max_life`; renamed. Tools: `tools/port/disasm_s.py s03d
      <func>` (a stub disassembled, calls named), `fdiff.py [--loose]` (also warns of a stale build).
      Done: no INCLUDE_ASM left, the stage table (`source/stage/s03d.c`) and `overlay2.c`'s pointers by symbol, and
      `s03d` links into the port (60 overlays). The replay goes on in `s03d`. Its first gameplay had 50 TLB misses in
      `MakePrimsRectangleSingle`: okajima/chafgrnd.c's chaff tiles are a `DG_PRIM_RECTANGLE` with rect NULL (found
      by logging `DG_MakePrim`'s rectangle prims without one), so the PS1 reads its RAM at 0: 3 and 0 (BizHawk).
      The port uses those values for a NULL rect (`libdg/prim.c`, `MGS_PORT`).
- [x] `GM_GameStatus` 0x20 at loop 12,102 (0:06:42.12, `s03d`): the port's voice stream ended a loop early (the
      SPU's pace). strctrl.c's `Act2` holds the actor's destroy while the PS1's next record still has the bit
      (`Port_TasStreamMayEnd`, bounded to 8 loops: a demo can be followed by another stream at once).
- [x] Crash at loop 12,652 (0:07:00.75): the guards' model names (strings split into 4-byte char arrays, 8-aligned
      by EE GCC) and zakocom.c's `ZakoComMgr` (`s03d_dword_800DC310` and the words after it, common symbols in the
      linker's order). `STR_PIECE`, and `overlay3.c`'s words in their own section.
- [x] Rand seed at loop 12,758 (0:07:05.19): a guard fell with action 0 instead of 34 at loop 12,696 (0:07:02.61);
      the action table had gaps (zeros in `.bss`, 8-aligned arrays). `-fno-zero-initialized-in-bss` for overlay
      files, `PS1_ALIGN(n)` on their arrays. Found with `tools/port/tas/zako_log.lua` (each guard's state per loop).
- [ ] Intermittent hang at loop 11,520 (0:06:22.25), 3 runs in about 12: the hang watch's PC report should show
      where.
- [x] Rand seed at loops 12,835 (0:07:07.76) and 12,879 (0:07:09.26): Snake's lip sync's `GV_RandS`
      (`sna_act_helper2_helper2_80033054`). `jimctrl.c` reads `get_str_counter()` directly, past the PS1's tick:
      now `Port_TasStrCounter`, `(tick * 105 - 1) / 64`, equal to the PS1's `str_tick_count` on loops 12,870 to 12,889.
      Guards matched throughout (`zako_log.lua`). Counting draws per loop between the two seeds found it.
- [x] Seed check before any overwrite (`tas: seed at loop`, in the log): no load hid a difference before 12,835.
- [ ] Late file reads wait at the loop's end (`file_wait`, from SH1's `file_sync`) and `FS_StreamGetData` stops at
      the PS1's bottom (`Port_TasStreamBottom`): neither moved a desync yet. Keep or drop once tested.
- [ ] One recorded disc timeline (`timeline.lua`): stream ends done, to loop 14,000; starts and data still to move. Keep the patches until it's shown to work better.
- [x] `STATE_CUT_IN` late at loop 13,015 (0:07:13.88): the stream's play end one loop late at 12,951; `Port_TasStreamPlayEnd`.
- [x] `GV_Clock` at loop 14,030 (0:07:50.07): BizHawk sampled between `GV_Time++` and the flip (also 15,110); corrected in `compare_trace.py`.
- [x] TLB misses in `s03d_800D47BC` (NULL guard; PS1 RAM at 0xB90 is 0).
- [x] `GV_PadData` at loop 15,061 (0:08:18.40): the press was lost where `STATE_PADRELEASE` zeroed the pads; `trace_to_pads.py` recovers it from line t+1's raw pads.
- [x] Fixed: play time from the recording each loop.
- [x] Fixed: jimctrl.c ends with the sound on the PS1's loops, from the timeline.
- [ ] Next desync: the FMV hang at loop 17,561 (0:09:35.55, `s04c`): StSetRing and CdRead2 are HAL stubs.
- [ ] Explain the timeline's 293,407 loops against the reference's 163,838.

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
