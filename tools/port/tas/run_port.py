#!/usr/bin/env python3
"""Replays the TAS in the port (PCSX2) and stops at the first desync: links the port with the replay tables, runs
it with the SH1 port's pcsx2_run.py, follows obj_ps2/tas_trace.log as it's written and compares each game loop
with the reference (compare_trace.py's fields). At the first loop that differs (from --from on) it closes PCSX2
and prints each field's first difference so far. Also ends at --last, when PCSX2 stops (crash, stall) or after
--seconds.

Known differences can be let through with --ignore, by field name (compare_trace.py's FIELDS), optionally for a
range of loops, and linkvarbuf by index: --ignore "rand seed@809-921" --ignore "linkvarbuf[92]". Every ignored
difference is still counted and reported at the end.

usage: run_port.py [--tables DIR (default ~/emu/tas)] [--ref TRACE] [--from 315] [--last T] [--seconds 900]
                   [--ignore SPEC]... [--no-link]"""
import argparse
import lzma
import os
import re
import signal
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from compare_trace import FIELDS, control_diff, linkvar_diff, same, when  # noqa: E402

REPO = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", ".."))
TRACE = os.path.join(REPO, "obj_ps2", "tas_trace.log")
PCSX2_RUN = os.path.join(REPO, "..", "silent-hill-1-ps2-port", "tools", "port", "pcsx2_run.py")


def parse_ignore(specs):
    """[(field name, linkvar index or None, first loop, last loop)]"""
    out = []
    for s in specs:
        m = re.fullmatch(r"(.+?)(?:\[(\d+)\])?(?:@(\d+)-(\d+))?", s)
        name, index, lo, hi = m.group(1), m.group(2), m.group(3), m.group(4)
        if name not in FIELDS.values():
            sys.exit("--ignore %s: no field %r (%s)" % (s, name, ", ".join(FIELDS.values())))
        out.append((name, int(index) if index else None, int(lo) if lo else 0, int(hi) if hi else 1 << 30))
    return out


def linkvar_indices(a, b):
    sa, sb = bytes.fromhex(a), bytes.fromhex(b)
    return {i // 2 for i in range(0, len(sa), 2) if sa[i:i + 2] != sb[i:i + 2]}


def ignored(name, t, p, r, rules):
    i = [k for k, v in FIELDS.items() if v == name][0]
    rules = [x for x in rules if x[0] == name and x[2] <= t <= x[3]]
    if not rules:
        return False
    if any(x[1] is None for x in rules):
        return True
    return linkvar_indices(p[i], r[i]) <= {x[1] for x in rules}  # only ignored linkvarbuf entries differ


def detail(name, p, r):
    i = [k for k, v in FIELDS.items() if v == name][0]
    return (linkvar_diff(p[i], r[i]) if name == "linkvarbuf" else control_diff(p[i], r[i])
            if name == "Snake CONTROL" else "port %s, PS1 %s" % (p[i], r[i]))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--tables", default="~/emu/tas")
    ap.add_argument("--ref", default=os.path.join(REPO, "tas", "reference", "trace.log.xz"))
    ap.add_argument("--from", dest="start", type=int, default=315)
    ap.add_argument("--last", type=int, default=0)
    ap.add_argument("--seconds", type=int, default=900)
    ap.add_argument("--ignore", action="append", default=[])
    ap.add_argument("--no-link", action="store_true")
    a = ap.parse_args()
    rules = parse_ignore(a.ignore)
    tables = os.path.expanduser(a.tables)

    if not a.no_link:
        env = dict(os.environ, MGS_MC_IMAGE=os.path.join(tables, "MovieSaveRam.bin"),
                   MGS_TAS_PADS=os.path.join(tables, "pads.bin"), MGS_TAS_RAW=os.path.join(tables, "raw.bin"),
                   MGS_TAS_TIME=os.path.join(tables, "time.bin"))
        if subprocess.run([sys.executable, os.path.join(REPO, "build", "link_ps2.py")], env=env,
                          stdout=subprocess.DEVNULL).returncode:
            sys.exit("link_ps2.py failed")

    ref_path = os.path.expanduser(a.ref)
    ref = {}
    for line in (lzma.open(ref_path, "rt") if ref_path.endswith(".xz") else open(ref_path)):
        f = line.split()
        if len(f) >= 14:
            ref[int(f[1])] = f
    print("reference: %d loops; comparing from loop %d" % (len(ref), a.start), flush=True)

    if os.path.exists(TRACE):
        os.remove(TRACE)
    log = open(os.path.join(REPO, "obj_ps2", "run_port.log"), "w")
    run = subprocess.Popen([sys.executable, PCSX2_RUN, os.path.join(REPO, "obj_ps2", "mgs_ps2.iso"),
                            "--seconds", str(a.seconds), "--stall", "15"], stdout=log, stderr=subprocess.STDOUT)
    first, ignored_first, last_t, desync, buf, f = {}, {}, -1, None, "", None
    try:
        while desync is None:
            ended = run.poll() is not None
            if f is None and os.path.exists(TRACE):
                f = open(TRACE)
            chunk = f.read() if f else ""
            buf += chunk
            *lines, buf = buf.split("\n")
            for line in lines:
                p = line.split()
                if len(p) < 14:
                    continue
                t = int(p[1])
                last_t = t
                if t < a.start or t not in ref:
                    continue
                r = ref[t]
                for name in (n for i, n in FIELDS.items() if not same(i, p, r)):
                    if ignored(name, t, p, r, rules):
                        ignored_first.setdefault(name, (t, detail(name, p, r)))
                    else:
                        first.setdefault(name, (t, r, detail(name, p, r)))
                if first:
                    desync = t
                    break
                if a.last and t >= a.last:
                    break
            if a.last and last_t >= a.last or ended and not chunk:
                break
            if not chunk:
                time.sleep(0.5)
    finally:
        if run.poll() is None:
            run.send_signal(signal.SIGTERM)  # pcsx2_run.py closes PCSX2
            run.wait(30)
        log.close()

    for name, (t, d) in sorted(ignored_first.items(), key=lambda x: x[1][0]):
        print("ignored: %-20s from loop %d: %s" % (name, t, d))
    if desync is None:
        why = "reached loop %d" % a.last if a.last and last_t >= a.last else "PCSX2 ended (see obj_ps2/run_port.log)"
        print("in sync to loop %d: %s" % (last_t, why))
        return 0 if a.last and last_t >= a.last else 1
    for name, (t, r, d) in first.items():
        print("DESYNC %-20s at loop %d (%s, movie %s, frame %s): %s" % (name, t, r[6], when(r[0]), r[0], d))
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
