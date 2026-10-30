#!/usr/bin/env python3
"""Compares the port's TAS trace (host:tas_trace.log, port/src/tas_replay.c) with BizHawk's (trace.lua),
game loop by game loop (GV_Time), and reports where each field first differs.

usage: compare_trace.py PORT_TRACE [REF_TRACE (default tas/reference/trace.log.xz; plain or .xz)] [--all N: list the first N
differing loops] [--from T: start at GV_Time T; the boot to the title takes more loops on the PS1 (its loads
loop longer), and the two line up again at New Game (GV_Time 315)]"""
import argparse
import lzma
import os

FIELDS = {2: "GV_Clock", 3: "GV_PassageTime", 4: "GM_GameStatus", 5: "rand seed", 6: "stage", 7: "GV_PadData",
          9: "GM_PlayerPosition", 10: "GM_AlertMode", 11: "GM_LoadRequest", 12: "DG_UnDrawFrameCount",
          13: "linkvarbuf"}


def load(path):
    loops = {}
    path = os.path.expanduser(path)
    for line in (lzma.open(path, "rt") if path.endswith(".xz") else open(path)):
        f = line.split()
        if len(f) >= 14:
            loops[int(f[1])] = f
    return loops


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
        diff = [n for i, n in FIELDS.items() if p[i] != r[i]]
        for n in diff:
            first.setdefault(n, t)
        if diff and listed < a.all:
            listed += 1
            print("  GV_Time %d (%s, movie frame %s): %s" % (t, r[6], r[0], ", ".join(diff)))
    if not first:
        print("identical in every compared loop")
        return 0
    for name, t in sorted(first.items(), key=lambda x: x[1]):
        i = [k for k, v in FIELDS.items() if v == name][0]
        p, r = port[t][i], ref[t][i]
        detail = linkvar_diff(p, r) if name == "linkvarbuf" else "port %s, PS1 %s" % (p, r)
        print("%-20s first differs at GV_Time %d (%s, movie frame %s): %s" % (name, t, ref[t][6], ref[t][0],
                                                                             detail))
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
