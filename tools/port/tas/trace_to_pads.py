#!/usr/bin/env python3
"""Makes the port's TAS replay tables from BizHawk's trace (trace.lua), for port/src/tas_replay.c:
 - pads.bin: for each change of GV_PadData[0..3], a little-endian u32 GV_Time and the 64 bytes;
 - raw.bin: for each change, a u32 GV_Time and the PS1's raw mts pads (pad_800C14E0[0..1]) and pad init
   states (pad_state_800C14F0[0..1]) as they were at the end of the loop before;
 - time.bin: for each loop from GV_Time 0, the tick FS_StreamGetTick returned (s32, 0x80000000: no stream;
   computed from mts_time and libfs/stream.c's fs_stream_last_time/next_time as the function does),
   GM_GameStatus, GM_LoadRequest, GV_PassageTime, the rand seed and GV_Clock.
Link them with MGS_TAS_PADS=<pads.bin> MGS_TAS_RAW=<raw.bin> MGS_TAS_TIME=<time.bin> python3 build/link_ps2.py.

usage: trace_to_pads.py [TRACE (default tas/reference/trace.log.xz; plain or .xz)] [OUT_DIR (default ~/emu/tas)]"""
import lzma
import os
import struct
import sys

REPO = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", ".."))
src = os.path.expanduser(sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "tas", "reference", "trace.log.xz"))
out_dir = os.path.expanduser(sys.argv[2] if len(sys.argv) > 2 else "~/emu/tas")
NO_TICK = -0x80000000


def stream_tick(now, last, nxt):
    """libfs/stream.c FS_StreamGetTick, as of the end of the frame (the call's vertical blank, mostly)."""
    if last == -1 and nxt == 0:
        return NO_TICK
    if nxt != 0:
        return -1 if last < 0 else now - last + nxt
    return now - last


out, prev, lines, time, ticks = bytearray(), None, 0, {}, 0
raw, prev_raw, last_line_raw = bytearray(), None, None
os.makedirs(out_dir, exist_ok=True)
for line in (lzma.open(src, "rt") if src.endswith(".xz") else open(src)):
    f = line.split()
    if len(f) < 14:
        continue
    lines += 1
    pads = bytes.fromhex(f[7])
    if len(pads) != 64:
        sys.exit("%s: GV_PadData isn't 64 bytes (a trace from before trace.lua recorded [0..3])" % src)
    if pads != prev:
        out += struct.pack("<I", int(f[1])) + pads
        prev = pads
    if len(f) < 17:
        sys.exit("%s: no stream timing fields (a trace from before trace.lua recorded them)" % src)
    if len(f) < 18:
        sys.exit("%s: no pad state field (a trace from before trace.lua recorded it)" % src)
    if last_line_raw is not None and last_line_raw != prev_raw:
        raw += struct.pack("<I", int(f[1])) + last_line_raw
        prev_raw = last_line_raw
    last_line_raw = bytes.fromhex(f[8]) + bytes.fromhex(f[17])
    tick = stream_tick(int(f[14]), int(f[15]), int(f[16]))
    ticks += tick != NO_TICK
    time[int(f[1])] = struct.pack("<iIIiIi", tick, int(f[4], 16), int(f[11]), int(f[3]), int(f[5], 16),
                                    int(f[2]))
pads_path, time_path = os.path.join(out_dir, "pads.bin"), os.path.join(out_dir, "time.bin")
open(pads_path, "wb").write(out)
open(os.path.join(out_dir, "raw.bin"), "wb").write(raw)
empty = struct.pack("<iIIiIi", NO_TICK, 0, 0, 0, 0, 0)
open(time_path, "wb").write(b"".join(time.get(t, empty) for t in range(max(time) + 1)))
print("%s: %d game loops, %d records; raw.bin: %d records; %s: %d loops with a stream tick"
      % (pads_path, lines, len(out) // 68, len(raw) // 28, time_path, ticks))
