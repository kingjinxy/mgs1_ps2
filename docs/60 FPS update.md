# 60 FPS update

Status as of 2026-10-27: discussion only, nothing built. Resume once the game boots on the PS2 and reaches
gameplay.

When resuming, in this order:
1. Draw the OT in the frame that built it (see "Input latency" below). This also helps at 30 fps, and
   nothing else here depends on it.
2. Check the pad timing (which step first sees a pad change).
3. Profile MGS's split between actor logic and the `DG_ChanlUnits` pipeline (see "CPU cost").
4. Choose between A and B with the profile in hand. Option B needs the replay system first.

Undecided. The user leans toward option B (logic at 60 Hz) for the PS2 and sees interpolation (A) as a
better fit for a port to stronger hardware. Claude's earlier analysis favoured A for its lower CPU cost
and because it leaves game logic untouched. Item 1 is worth doing either way.

## How MGS1 times frames

- **Gameplay is a fixed step.** `mts_wait_vbl(DG_FrameRate)` in `source/libdg/dgd.c` (`Act1`) paces the
  loop. `DG_FrameRate` is 2 (30 fps). Every actor runs one step per frame.
- **Delta time exists but is barely used.** `GV_PassageTime` (`source/libgv/gvd.c`) is read in 7 files
  only: fade, telop, life_up, env_snd, vibrate, and the play-time total in `gamed.c`. Movement, animation
  (`GM_ActMotion` advances one keyframe per call), AI timers and effects are all per frame.
- **The engine changes the rate itself.** `wt_area.c` sets 3 (20 fps), `ending2.c` sets 1 (60 fps).
  Setting 1 everywhere runs the game at double speed.
- **Cutscenes (demo files) follow real time, at 30 fps.** `ActFile` and `ActStream`
  (`source/kojo/demothrd.c`) compute the frame as `(VSync(-1) - start_time) / 2` and skip ahead when
  rendering falls behind. Each record holds absolute position, rotation and joint rotations per model
  (`ShowScene`, `source/kojo/demoexec.c`), so frames N and N+1 can be interpolated without changing
  the data. Effects that demos spawn (`ShowEffect`, the M1 and Hind helpers) are ordinary per-frame
  actors. Many story scenes are GCL scripts driving live actors, which makes them gameplay for timing.
- **Rendering is a separate pass.** Actors set matrices and object state. `DG_EndFrame` →
  `DG_SortChanlSystem` then runs the `DG_ChanlUnits` pipeline (transform, divide, sort into the OT) for
  the whole scene. Effects that build `DG_PRIM` packets inside their own `Act` are the exception.

## Options

### A. Interpolation: logic at 30 Hz, drawing at 60 Hz

Keep previous and current transforms per object (`control.mov/rot`, `object.rots`, camera). On the odd
vblank, run the `DG_ChanlUnits` pipeline again on transforms halfway between the two.

- **Cutscenes first.** Interpolate demo records N and N+1 using a fractional frame number. Streamed
  demos need one record of lookahead before the previous one is freed (`FS_StreamGetData` /
  `FS_StreamClear`).
- **Gameplay next,** using the same per-object transform history.
- Game logic is untouched, so the matching build and the DuckStation comparison still hold.

#### Input latency

Order the work like this:

```
vblank 0: show step N           ← read pad, compute step N+1
vblank 1: show lerp(N, N+1, ½)
vblank 2: show step N+1         ← read pad, compute N+2
```

- An input becomes partly visible one vblank after it's read and fully visible after two. That is about
  the same as the original game. Step N+1 has to finish within one vblank.
- Poll the pad every vblank. Latch presses that are shorter than a step, so they aren't lost.
- In first-person view and while aiming, rotate the camera on the in-between frame from the newest pad
  state. This changes only the view, not game state.
- Check that the HAL doesn't keep an extra buffered frame between the GS draw and the display.

Further reductions, in order of value for the risk:
1. **Display chain** (no visual cost; also helps at 30 fps):
   - **Draw the OT in the frame that built it.** MGS keeps a PS1 pipeline: frame F's step sorts its OT at
     the end (`DG_EndFrame`). Then, after the next vblank wait, `DG_StartFrame` (`source/libdg/frame.c`)
     shows the other buffer with `PutDispEnv`, and only then starts `DrawOTag` of frame F's OT. Frame F
     therefore appears one game frame after it was sorted: input → screen is about 2 game frames plus
     scan-out. On the PS1 the GPU drew in parallel with the CPU's next frame. On the PS2 the OT's
     translation is EE work in the HAL anyway, so a port path can call `DrawOTag` at `DG_EndFrame`, wait
     for the GS (DrawSync), and show that buffer at the next vblank. That removes one game frame (33 ms at
     30 fps). Keep `DG_UnDrawFrameCount`, the `GV_PAUSE_READERROR` pause and `DG_HikituriFlag` behaving the
     same. The work has to fit before the vblank, not spread over two frames.
   - **Pad sampling is fixed at one per vblank.** rom0 PADMAN on the IOP reads the pad once per vblank
     (see `Port_PadShutdown` in the HAL's `pad_ps2.c`). The HAL's poll thread (`HAL_GAME_PAD_THREAD`,
     priority 2) copies the data right after the interrupt, and `GV_UpdatePadSystem` runs right after the
     vblank wait (`dgd.c` `Act1`). That should already be the freshest data. To check: timestamp a pad
     change in the poll thread against the step that sees it. If it's a vblank late (PADMAN's transfer
     finishing after the interrupt), wait for the transfer instead.
   - **Video:** 480p or 240p rather than 480i where the TV allows. This is outside the game's control.
2. **Starting the step just in time doesn't help on the PS2.** The idea was to start the step as late as
   possible so it reads fresher input. But PADMAN samples once per vblank, at the same moment as the
   flip. So the newest sample is always the one taken at the vblank the step follows, and the order
   "vblank: read pad, step, draw the in-between frame, show it at the next vblank" is already the
   minimum. The only requirement is that step + in-between draw fit in one vblank (about 4.9 M EE
   cycles). If they don't, the in-between frame shows a vblank late. Fall back to showing step N again
   for that vblank, and log it. Polling the pad faster would need a replacement for PADMAN; not worth it.
3. **Predict the player on the in-between frame:** turn the camera and Snake's facing from the newest
   stick state, for display only. Logic corrects it on the next step. This works well for the camera; for
   Snake, a step that disagrees (he hit a wall) shows as a one-vblank wobble.
4. **Extrapolate instead of interpolating:** show step N+1 as soon as it's computed and extrapolate to
   N+1.5 on the next vblank. This saves one more vblank, but objects overshoot when they stop or turn and
   at collisions. Last resort; probably only for the camera.

#### Camera cuts and teleports

The frame rate never drops: something is drawn every vblank. Interpolation is turned off per object,
not per frame:

- **Cut:** the in-between frame takes step N+1's camera while objects keep interpolating. The cut appears
  one vblank early, with no hitch.
- **Teleport:** only the warped object snaps.
- **Detecting cuts:** explicit hooks where the game resets the camera (camera mode changes, area loads,
  demo cut records, codec and menu transitions). As a fallback, snap when the camera's position or angle
  jumps past a threshold. Angles are in 4096 units: use the shortest path and handle the wrap.

#### One-step effects

Match objects between steps by identity: the `DG_OBJS` pointer plus a generation counter, so a reused
slot isn't mistaken for the same object.

| Case | Step N | In-between frame | Step N+1 |
|---|---|---|---|
| In both steps | shown | interpolated | shown |
| New in N+1 (spawn, muzzle flash) | – | shown at N+1's pose | shown |
| Gone in N+1 (despawn) | shown | hidden | – |

- A one-step effect stays on screen for two vblanks, the same as on the PS1.
- Flicker and blinking (`GV_Time & 1`, the damage blink) toggle only on logic steps.
- Screen-wide effects: interpolate fade levels where they're continuous, otherwise hold the value.
- Effects built in screen space (`DG_PRIM` vertices written in `Act`) stay at 30 Hz at first. Convert the
  visible ones (smoke, the stealth camo, lasers) later so they store world positions to interpolate.

### B. Logic at 60 Hz

Run every actor every vblank and rescale its constants.

| Pattern | 60 Hz change |
|---|---|
| Velocity per frame | halve |
| Acceleration, gravity | quarter it, and halve the starting velocities |
| Frame-count timers | double the limits |
| Smoothing `x += (t - x) * k` | `k' = 1 - sqrt(1 - k)` (1/4 becomes about 0.134) |
| Chance per frame | halve the odds |
| Every Nth frame (`GV_Time & 1`, `% 4`) | case by case |
| `GM_ActMotion` keyframes | add interpolation between keyframes in the motion system |
| GCL waits in frames | scale them in the interpreter |

Problems:
- Halving small fixed-point values rounds, so some fields need extra fractional bits.
- Hundreds of actor files each have their own constants.
- Every change needs a guard so the matching build still matches.

#### Plan: replay-driven, one actor at a time

- Run the loop at 60 Hz. Each actor type gets a "converted" flag, and unconverted actors only act on even
  ticks. The game then runs at normal speed throughout the work, and each actor is done once converted.
- Order: loop, camera and core libraries (`GM_ActMotion`, `GM_ActControl`, the GCL waits), then Snake,
  guards, effects, bosses.
- Replays (as in SH1, `../silent-hill-1-ps2-port/replays.md`) check within a tolerance, not for an exact
  match. Rounding and the RNG call count make an exact match impossible. Compare every second 60 Hz tick
  against the 30 Hz trace: allow small position and angle errors, and flag differences in discrete
  state (actor counts, AI modes, health, alert phase, area loads). Use short recordings, since runs
  eventually go different ways.
- Tooling:
  - per-actor trace dumps (`GV_ACT` name, position, AI state, timers)
  - an RNG call counter per actor: a converted actor that doubles its calls still rolls every tick
  - a static scan of `Act` functions for `+=` with literals, timers compared with literals, and
    `/ N` toward a target
  - the SH1 fix for file-timing desync

### C. Delta time (considered, not recommended)

Scale every actor by the elapsed time (`GV_PassageTime` already exists but is read in only 7 files).

Pros:
- Runs at any rate: 60, 30 under load, 50 Hz, or higher on stronger hardware.
- A slow frame doesn't slow the game down.

Cons:
- Every site from option B still needs changing, and each change is harder: a formula in `dt` instead of
  a fixed constant (powers of `k` for smoothing, `dt²` terms for acceleration, a chance per tick
  converted to a probability over `dt`).
- Fixed-point rounding changes from frame to frame, so a jump's height or a walk's distance depends on
  the frame rate. MGS's numbers were tuned for one fixed step. SH1 was easy because its developers wrote
  and tuned it for delta time; here it would be added afterwards.
- A large `dt` (a load hitch) moves objects past walls and triggers, so `dt` must be capped.
- Timers that cross a threshold in the middle of a frame fire at different moments, so AI and script
  timing jitter.
- Replays only reproduce if every frame's `dt` is recorded (SH1 does this). A replay can't be checked
  at a different frame rate, so the replay plan above loses its main test.
- More combinations to test: every rate behaves slightly differently.

A fixed 60 Hz step that runs two steps when a frame is late (B with catch-up) also keeps a slow frame
from slowing the game, and stays deterministic. For variable-rate hardware, A (fixed logic plus
interpolation) handles any display rate. So C has no advantage either option lacks.

## CPU cost compared with the SH1 port

SH1 at 60 fps (`g_IntervalVBlanks` 2 → 1, `SH1_FPS=60`) runs the whole frame twice as often. Per frame,
about 4.9 M EE cycles are available. The first profile measured 3.15 M for the game update, of which
about 1.97 M was software GTE, and 1.28 M for the GS translation, so the whole 60 fps load is about 2×
the 30 fps load. It was made to fit by speeding up the GTE (update 2.42 M) and the GS translation (about
1.2 M) (`../silent-hill-1-ps2-port/Running Walkthrough.md`, "60 fps: option and first profile" and the
sections after it).

- **Option B costs the same as SH1:** all actor logic, the transform pipeline and the GS translation run
  every vblank.
- **Option A costs less:** actor logic stays at 30 Hz. The `DG_ChanlUnits` pipeline (most of the
  software-GTE work) and the GS translation run every vblank, plus a small cost to save and interpolate
  transforms.
- In both options, drawing has to fit in one vblank. The GTE and GS-translation speedups carried over
  from SH1 through the shared HAL are what make either option possible.
- To do: profile MGS's own split between actor logic and `DG_ChanlUnits` once gameplay runs, to measure
  how much A saves.
