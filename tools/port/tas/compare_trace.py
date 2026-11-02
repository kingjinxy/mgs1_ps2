#!/usr/bin/env python3
"""Compares the port's TAS trace (host:tas_trace.log, port/src/tas_replay.c) with BizHawk's (trace.lua),
game loop by game loop (GV_Time: one pass of the game's main loop, 30 a second in play), and reports where each
field first differs, with the time in the TAS movie (h:mm:ss.ss) and its frame.

usage: compare_trace.py PORT_TRACE [REF_TRACE (default tas/reference/trace.log.xz; plain or .xz)] [--all N: list the first N
differing loops] [--from T: start at GV_Time T; the boot to the title takes more loops on the PS1 (its loads
loop longer), and the two line up again at New Game (GV_Time 315)]"""
import argparse
import lzma
import os

FIELDS = {2: "GV_Clock", 3: "GV_PassageTime", 4: "GM_GameStatus", 5: "rand seed", 6: "stage", 7: "GV_PadData",
          9: "GM_PlayerPosition", 10: "GM_AlertMode", 11: "GM_LoadRequest", 12: "DG_UnDrawFrameCount",
          13: "linkvarbuf", 22: "GM_PlayerStatus", 23: "Snake CONTROL"}

# CONTROL's fields that are the same on both machines (offset, size, name); the pointers differ
CONTROL = [(0, 8, "mov"), (8, 8, "rot"), (48, 2, "name"), (50, 2, "height"), (52, 2, "hzd_height"),
           (68, 8, "step"), (76, 8, "turn"), (84, 1, "interp"), (85, 1, "skip_flag"), (87, 1, "grounded"),
           (88, 1, "n_touches"), (96, 16, "vecs"), (120, 4, "levels")]


def fix_clock(loops):
    """BizHawk's frame can end between gvd.c's GV_Time++ and its GV_Clock flip: that line has the old clock, between
    two lines of the same one (14,030 and 15,110; a real hold, dgd.c's, shifts the parity instead)."""
    for t, f in loops.items():
        if t - 1 in loops and t + 1 in loops and loops[t - 1][2] == f[2] == loops[t + 1][2]:
            f[2] = "1" if f[2] == "0" else "0"


def load(path):
    loops = {}
    path = os.path.expanduser(path)
    for line in (lzma.open(path, "rt") if path.endswith(".xz") else open(path)):
        f = line.split()
        if len(f) >= 14:
            loops[int(f[1])] = f
    fix_clock(loops)
    return loops


def when(frame):
    """A movie frame as the time in the TAS movie (59.94 frames a second), h:mm:ss.ss."""
    s = int(frame) / 59.94005994
    return "%d:%02d:%05.2f" % (s // 3600, s % 3600 // 60, s % 60)


def control_key(h):
    if h == "-":
        return h
    b = bytes.fromhex(h)
    return b"".join(b[o:o + n] for o, n, _ in CONTROL)


def control_diff(a, b):
    if "-" in (a, b):
        return "port %s, PS1 %s" % (a[:16], b[:16])
    pa, pb = bytes.fromhex(a), bytes.fromhex(b)
    return ", ".join("%s %s/%s" % (name, pa[o:o + n].hex(), pb[o:o + n].hex()) for o, n, name in CONTROL
                     if pa[o:o + n] != pb[o:o + n])


def same(i, p, r):
    if i >= len(p) or i >= len(r):
        return True  # a field only the debug traces have
    if i == 23:
        return control_key(p[i]) == control_key(r[i])
    return p[i] == r[i]


def linkvar_diff(a, b):
    sa, sb = bytes.fromhex(a), bytes.fromhex(b)
    return ", ".join("[%d] %d/%d" % (i // 2, int.from_bytes(sa[i:i + 2], "little", signed=True),
                                      int.from_bytes(sb[i:i + 2], "little", signed=True))
                     for i in range(0, len(sa), 2) if sa[i:i + 2] != sb[i:i + 2])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("port")
    ap.add_argument("ref", nargs="?", default=os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..",
                                                           "..", "tas", "reference", "trace.log.xz"))
    ap.add_argument("--all", type=int, default=0)
    ap.add_argument("--from", dest="start", type=int, default=0)
    a = ap.parse_args()
    port, ref = load(a.port), load(a.ref)
    common = sorted(t for t in set(port) & set(ref) if t >= a.start)
    if not common:
        print("no game loops in common")
        return 1
    print("port: %d loops (to GV_Time %d); reference: %d; compared: %d" % (len(port), max(port), len(ref),
                                                                           len(common)))
    first, listed = {}, 0
    for t in common:
        p, r = port[t], ref[t]
        diff = [n for i, n in FIELDS.items() if not same(i, p, r)]
        for n in diff:
            first.setdefault(n, t)
        if diff and listed < a.all:
            listed += 1
            print("  loop %d (%s, movie %s, frame %s): %s" % (t, r[6], when(r[0]), r[0], ", ".join(diff)))
    if not first:
        print("identical in every compared loop")
        return 0
    for name, t in sorted(first.items(), key=lambda x: x[1]):
        i = [k for k, v in FIELDS.items() if v == name][0]
        p, r = port[t][i], ref[t][i]
        detail = (linkvar_diff(p, r) if name == "linkvarbuf" else control_diff(p, r) if name == "Snake CONTROL"
                  else "port %s, PS1 %s" % (p, r))
        print("%-20s first differs at loop %d (%s, movie %s, frame %s): %s"
              % (name, t, ref[t][6], when(ref[t][0]), ref[t][0], detail))
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
