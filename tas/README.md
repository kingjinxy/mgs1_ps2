# TAS regression test data

The plan and its status: `docs/TAS Testing Plan.md`. Scripts: `tools/port/tas/`.

## What's here

- `movie/metalgearsolidintegral-allbosses-theenglishman.bk2`: TASVideos submission #5139 (published),
  theenglishman's "all bosses, BIGBOSS rank" run of Metal Gear Solid: Integral (J), 1:27:05.25.
  BizHawk 1.11.4 (Octoshock core), 313,202 frames, both discs (swap at frame 181,883), DualShock in both ports,
  BIOS v1.0J (`ps-10j.bin`, SHA-1 `343883a7b555646da8cee54aadd2795b6e7dd070`). It starts from a memory card
  (`MovieSaveRam.bin` inside the zip, both cards back to back) holding `BISLPM-86247G:E0pBAA`, a cleared save that
  unlocks Extreme on the New Game menu; the run picks Extreme at frame 1,582.
- `reference/trace.log.xz`: the PS1 game's state on every game loop of the full movie, from
  `tools/port/tas/trace.lua` (163,838 loops, 21 fields; the line format is at the top of that script). Made
  2026-10-30, with the game task's wait, stream data and CD file read fields (18-20); fields 0-17 are identical
  to the first reference's, and two runs of the script give identical lines.
- `reference/synccheck.log`: the first full sync check (`synccheck.lua`): the stage every 600 frames.

## Making the reference again (only if trace.lua changes)

Needs, outside the repo (the disc images and BIOS aren't in it):

1. BizHawk 1.11.4 from GitHub (`TASEmulators/BizHawk` releases, `BizHawk-1.11.4.zip`) in `~/emu/bizhawk-1.11.4`.
   It's 32-bit Windows .NET: 32-bit Wine (`wine32:i386`) and a prefix `~/emu/wine-bizhawk` (`WINEARCH=win32`)
   with wine-mono 9.4.0 (`madewokherd/wine-mono` releases, the x86 `.msi`, `wine msiexec /i`).
2. `ps-10j.bin` in `~/emu/bizhawk-1.11.4/Firmware/`.
3. The discs as cue/bin (BizHawk 1.11.4 can't read CHD) in `~/emu/mgs-integral/`:
   `chdman extractcd -i "<Disc N>.chd" -o discN.cue -ob discN.bin` for discs 1 and 2 from `ps1-original/`.
4. In `~/emu/tas/`: the movie as `mgs.bk2` and `tools/port/tas/mgs.xml` (the two-disc bundle).

Then `tools/port/tas/run_bizhawk.sh tools/port/tas/trace.lua` (no clicks; about an hour at 1.4x speed; prints
`OK: movie played to the end` and BizHawk closes itself). The trace is `~/emu/tas/trace.log`; compress it into
`reference/` with `xz -9`. `run_bizhawk.sh` sets BizHawk's config each time (OpenGL display: Direct3D's
shaders don't compile under Wine; sound off; frame skip; the BIOS; Lua console auto-load).

## Replaying in the port

```
python3 tools/port/tas/trace_to_pads.py                  # tables to ~/emu/tas from reference/trace.log.xz
unzip -o -d ~/emu/tas tas/movie/*.bk2 MovieSaveRam.bin   # the movie's memory cards
MGS_MC_IMAGE=~/emu/tas/MovieSaveRam.bin MGS_TAS_PADS=~/emu/tas/pads.bin MGS_TAS_RAW=~/emu/tas/raw.bin \
  MGS_TAS_TIME=~/emu/tas/time.bin python3 build/link_ps2.py
python3 ../silent-hill-1-ps2-port/tools/port/pcsx2_run.py obj_ps2/mgs_ps2.iso --seconds 120 --stall 15
python3 tools/port/tas/compare_trace.py obj_ps2/tas_trace.log --from 315
```

Or, stopping at the first desync instead of running for a fixed time (links, runs PCSX2, follows the trace live
and closes PCSX2 at the first differing loop; `--ignore` lets known differences through, reported at the end):

```
python3 tools/port/tas/run_port.py --ignore "linkvarbuf[92]@490-1000" --ignore "rand seed@809-921"
```

The port writes its trace to `obj_ps2/tas_trace.log` (`host:`). `--from 315` starts at New Game: before it, the
boot to the title takes a different number of loops on the two.
