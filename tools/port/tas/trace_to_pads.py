#!/usr/bin/env python3
"""Makes the port's TAS replay tables from BizHawk's trace (trace.lua), for port/src/tas_replay.c:
 - pads.bin: for each change of GV_PadData[0..3], a little-endian u32 GV_Time and the 64 bytes;
 - loads.bin: at each PS1 load end, the loop and GV_PadData as recorded (tas_replay.c's realign);
 - raw.bin: for each change, a u32 GV_Time and the PS1's raw mts pads (pad_800C14E0[0..1]) and pad init
   states (pad_state_800C14F0[0..1]) at the loop's vertical blank;
 - time.bin: for each loop from GV_Time 0, the tick FS_StreamGetTick returned (s32, 0x80000000: no stream;
   computed from mts_time and libfs/stream.c's fs_stream_last_time/next_time as the function does),
   GM_GameStatus, GM_LoadRequest, GV_PassageTime, the rand seed, GV_Clock and how far the stream's data had come
   in (fs_stream_bottom's offset in the stream heap, -1: no heap) and how many streams the PS1 had started
   (FS_StreamTickStart: fs_stream_last_time from -1, the FS_StreamTaskStart value, to a vertical blank, with
   fs_stream_next_time still 0), the CD file read's bytes still to come after the loop (FS_LoadFileSync) and
   gTotalFrameTime (the play time) before the loop.
Link them with MGS_TAS_PADS=<pads.bin> MGS_TAS_RAW=<raw.bin> MGS_TAS_TIME=<time.bin> python3 build/link_ps2.py.

usage: trace_to_pads.py [TRACE (default tas/reference/trace.log.xz; plain or .xz)] [OUT_DIR (default ~/emu/tas)]"""
import lzma
import os
import struct
import sys

from compare_trace import fix_clock

REPO = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", ".."))
src = os.path.expanduser(sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "tas", "reference", "trace.log.xz"))
out_dir = os.path.expanduser(sys.argv[2] if len(sys.argv) > 2 else "~/emu/tas")
NO_TICK = -0x80000000
STATE_PADRELEASE = 0x10000000  # GM_GameStatus (g_define.h)


def stream_tick(now, last, nxt):
    """libfs/stream.c FS_StreamGetTick, as of the end of the frame (the call's vertical blank, mostly)."""
    if last == -1 and nxt == 0:
        return NO_TICK
    if nxt != 0:
        return -1 if last < 0 else now - last + nxt
    return now - last


# trace.lua samples at the end of the video frame in which GV_Time became N: after gvd.c's Act (GV_Time, GV_Clock,
# GV_PassageTime of loop N), during dgd.c's wait for the vertical blank, before loop N's pad update and actors.
# So line N's game state is loop N-1's result, and loop N's pads are on line N+1. Checked at the title (line N's
# pads: New Game a loop late) and the intro's end. In the dock it's wrong: DuckStation shows Snake uses a press in
# the loop that read it (tools/port/gdb/snake_turn_ps1.py), so the PS1's line 1012 held loop 1012's pads and the
# port's Snake, given them in loop 1011, turned a loop early. The game task's wait (field 18) doesn't tell the
# cases apart (other waits than dgd.c's within a loop): not settled (docs/TAS Testing Plan.md).
rows = []
for line in (lzma.open(src, "rt") if src.endswith(".xz") else open(src)):
    f = line.split()
    if len(f) < 14:
        continue
    if len(bytes.fromhex(f[7])) != 64:
        sys.exit("%s: GV_PadData isn't 64 bytes (a trace from before trace.lua recorded [0..3])" % src)
    if len(f) < 22:
        sys.exit("%s: no stream timing, pad state, stream data, file read or play time fields (an older trace.lua)"
                 % src)
    rows.append(f)
fix_clock({int(f[1]): f for f in rows})  # BizHawk's mid-loop samples: tas_replay.c copies the clock's holds
out, prev, raw, prev_raw, time, ticks, starts = bytearray(), None, bytearray(), None, {}, 0, 0
for i, f in enumerate(rows):
    t = int(f[1])
    n = rows[i + 1] if i + 1 < len(rows) else f
    pads = bytes.fromhex(n[7])                      # the pads loop t's actors used
    if int(n[4], 16) & STATE_PADRELEASE or int(n[12]) > 0:
        # zeroed (GV_UpdatePadSystem): [2]/[3].status hold the result, not the controller, which a second update
        # in the loop needs (script.c's PadCmd at loop 5,110: the held buttons' release); mts's raw pads have it,
        # as the loop read them: line t's, as raw.bin (loop 9,252's circle at the elevator, gone on line t+1).
        # Only where the recorded buttons are 0: a flag set after the loop's update (loop 5,002) left them as read
        rp = bytes.fromhex(f[8])
        pads = bytearray(pads)
        for port in (0, 1):
            o = (2 + port) * 16
            if pads[o] == pads[o + 1] == 0:
                # and a press the loop read (its press field) that the raw pads only show on line t+1 (loop 15,060)
                nr = bytes.fromhex(n[8])
                held = ~(rp[port * 8 + 2] | rp[port * 8 + 3] << 8) & 0xFFFF
                late = ~(nr[port * 8 + 2] | nr[port * 8 + 3] << 8) & 0xFFFF
                press = pads[port * 16 + 4] | pads[port * 16 + 5] << 8
                pads[o:o + 2] = (held | late & press).to_bytes(2, "little")
        pads = bytes(pads)
    if pads != prev:
        out += struct.pack("<I", t) + pads
        prev = pads
    r = bytes.fromhex(f[8]) + bytes.fromhex(f[17])  # raw pads at loop t's vertical blank
    if r != prev_raw:
        raw += struct.pack("<I", t) + r
        prev_raw = r
    last, nxt = int(n[15]), int(n[16])              # the stream clock after loop t's call
    if nxt != 0 and last >= 0 and last != int(f[15]):
        tick = nxt                                  # the call updated it: it returned the new value
    elif int(f[15]) >= 0 and int(f[16]) == 0:
        tick = int(f[14]) + 1 - int(f[15])          # started, no sound yet: the first call's (the audio packet's
                                                    # FS_StreamSoundMode can reset the clock in the same loop)
    else:
        tick = stream_tick(int(f[14]) + 1, last, nxt)  # the call comes one vertical blank after the sample
        if tick == NO_TICK:                         # reset (FS_StreamTaskStart) after the loop's calls
            tick = stream_tick(int(f[14]) + 1, int(f[15]), int(f[16]))
    ticks += tick != NO_TICK
    if int(f[15]) == -1 and last >= 0 and nxt == 0:
        starts += 1                                 # loop t started a stream's clock
    # status: line t+1; load request, passage, seed, clock: line t; stream data: what loop t could have used (line
    # t+1); stream starts: up to and including loop t; file read: line t+1; play time: line t
    time[t] = struct.pack("<iIIiIiiIii", tick, int(n[4], 16), int(f[11]), int(f[3]), int(f[5], 16), int(f[2]),
                          int(n[19]), starts, int(n[20]), int(f[21]))
# ticks.bin: for each loop, the PS1's mts tick when its actors ran, as game logic reads it (s10a's Wolf burns
# tick % 256 rand() calls when made; port Port_GameTick): the next line's sample, but for the loops in TICK_AT.
# shortcut: TICK_AT is the tick read mid-loop, found by hand (the trace only samples between loops; a stage's
# scenario can take 30 blanks: 90,361 at the end of loop 47,488, Wolf's burn at 90,359; s10a again at 57,275,
# 107,407 and 107,405: 141 draws, so the rats' rolls after it are the PS1's; s12a's Wolf at 93,335, 176,377 and
# 176,376: the load-end loop's total, 2,701). All so far are Wolf's burn in a load-end loop, 1-2 blanks before the
# next line. Add a loop when a tick-dependent burn desyncs; record the tick in trace.lua if they become common.
TICK_AT = {47488: 90359, 57275: 107405, 93335: 176376}
# By loop (Port_GameTick reads it by GV_Time), as time.bin: a loop without a line has the next line's. Written by line
# until loop 93,335 (s12a: Wolf's burn read the tick 7 lines late), harmless before the first loop without a line.
tick_at = {int(f[1]): TICK_AT.get(int(f[1]), int(n[14])) for f, n in zip(rows, rows[1:])}
tick_list, nxt_tick = [], 0
for t in range(max(tick_at), -1, -1):
    nxt_tick = tick_at.get(t, nxt_tick)
    tick_list.append(nxt_tick)
ticks_bin = b"".join(struct.pack("<I", x) for x in reversed(tick_list))
open(os.path.join(out_dir, "ticks.bin"), "wb").write(ticks_bin)
# loads.bin: at each PS1 load end (the line whose GM_LoadRequest is back to 0), a u32 GV_Time and that line's
# GV_PadData as recorded (pads.bin's records can have [2]/[3] rebuilt): tas_replay.c's realign at the load's end
loads = bytearray()
for prev, f in zip(rows, rows[1:]):
    if int(prev[11]) and not int(f[11]):
        loads += struct.pack("<I", int(f[1])) + bytes.fromhex(f[7])
open(os.path.join(out_dir, "loads.bin"), "wb").write(loads)
lines = len(rows)
pads_path, time_path = os.path.join(out_dir, "pads.bin"), os.path.join(out_dir, "time.bin")
open(pads_path, "wb").write(out)
open(os.path.join(out_dir, "raw.bin"), "wb").write(raw)
# a loop without a line (two loops in one video frame, as after a hold): no passage, the next line's GV_Clock and
# play time (tas_replay.c's hold check, its display; zeros made the play time 0 at loop 60,536)
records, nxt = [], None
for t in range(max(time), -1, -1):
    if t in time:
        nxt = struct.unpack("<iIIiIiiIii", time[t])
    records.append(time.get(t) or struct.pack("<iIIiIiiIii", NO_TICK, 0, 0, 0, 0, nxt[5], -1, starts, 0, nxt[9]))
open(time_path, "wb").write(b"".join(reversed(records)))
print("%s: %d game loops, %d records; raw.bin: %d records; %s: %d loops with a stream tick"
      % (pads_path, lines, len(out) // 68, len(raw) // 28, time_path, ticks))
