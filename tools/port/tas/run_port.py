#!/usr/bin/env python3
"""Replays the TAS in the port (PCSX2) and stops at the first desync: links the port with the replay tables, runs
it with the SH1 port's pcsx2_run.py, follows obj_ps2/tas_trace.log as it's written and compares each game loop
with the reference (compare_trace.py's fields). At the first loop that differs (from --from on) it closes PCSX2
and prints each field's first difference so far. Also ends at --last, when PCSX2 stops (crash, stall) or after
--seconds.

Known differences can be let through with --ignore, by field name (compare_trace.py's FIELDS), optionally for a
range of loops, and linkvarbuf by index: --ignore "rand seed@809-921" --ignore "linkvarbuf[92]". Every ignored
difference is still counted and reported at the end.

At a desync it also takes screenshots of that loop for the record (unless --no-shots): the port again to that loop,
not linked again (host:tas_shot.txt: its frame dumped), and the PS1 game in the PCSX-Redux control run (redux_replay.lua,
TAS_SHOT) at the same time; tas/shots/loop_<T>.png is PS1 | port | difference (white: differs, both scaled to the
PS1's 320 wide). The two are a frame apart if the dump and Redux's screen aren't from the same loop's drawing:
redux_<T+1> is kept in obj_ps2/shots/ to check.

usage: run_port.py [--tables DIR (default ~/emu/tas)] [--ref TRACE] [--from 315] [--last T] [--seconds 900]
                   [--ignore SPEC]... [--no-link] [--no-shots] [--shot T (dump loop T's frame)]"""
import argparse
import glob
import hashlib
import lzma
import os
import re
import shutil
import signal
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from compare_trace import FIELDS, control_diff, fix_clock, linkvar_diff, same, when  # noqa: E402

REPO = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", ".."))
TRACE = os.path.join(REPO, "obj_ps2", "tas_trace.log")
PCSX2_RUN = os.path.join(REPO, "..", "silent-hill-1-ps2-port", "tools", "port", "pcsx2_run.py")
SHOTS = os.path.join(REPO, "obj_ps2", "shots")
OFFSCREEN = os.path.join(REPO, "tools", "port", "offscreen")
REDUX = os.path.expanduser("~/emu/pcsx-redux/PCSX-Redux-HEAD-x86_64.AppImage")
BIOS = os.path.expanduser("~/emu/bizhawk-1.11.4/Firmware/ps-10j.bin")
DISC1 = os.path.expanduser("~/emu/mgs-integral/disc1.cue")


def redux(tables, t):
    """the control run to loop t + 1, its screen at t and t + 1 in SHOTS"""
    cards = open(os.path.join(tables, "MovieSaveRam.bin"), "rb").read()
    for i in (0, 1):  # Redux saves the cards on exit: fresh ones each time
        open(os.path.join(SHOTS, "card%d.mcd" % (i + 1)), "wb").write(cards[i * 131072:(i + 1) * 131072])
    env = dict(os.environ, TAS_DIR=tables, TAS_LAST=str(t + 1), TAS_SHOT=str(t), TAS_SHOT_DIR=SHOTS,
               TAS_OUT=os.path.join(SHOTS, "redux_trace.log"))
    return subprocess.Popen([OFFSCREEN, REDUX, "-no-ui", "-debugger", "-run", "-noupdate", "-safe", "-interpreter", "-fastboot",
                             "-bios=" + BIOS, "-memcard1=" + os.path.join(SHOTS, "card1.mcd"),
                             "-memcard2=" + os.path.join(SHOTS, "card2.mcd"), "-iso=" + DISC1,
                             "-dofile=" + os.path.join(REPO, "tools", "port", "tas", "redux_replay.lua")],
                            env=env, cwd=os.path.dirname(REDUX), stdout=open(os.path.join(SHOTS, "redux.log"), "w"),
                            stderr=subprocess.STDOUT)


def ps1_image(t):
    from PIL import Image
    w, h, *_, bpp = open(os.path.join(SHOTS, "redux_%d.txt" % t)).read().split()  # bpp: "cdata<enum N>: 0"
    w, h, raw = int(w), int(h), open(os.path.join(SHOTS, "redux_%d.raw" % t), "rb").read()
    if bpp == "0":  # 15-bit
        px = bytearray()
        for i in range(0, w * h * 2, 2):
            v = raw[i] | raw[i + 1] << 8
            px += bytes(((v & 31) * 255 // 31, (v >> 5 & 31) * 255 // 31, (v >> 10 & 31) * 255 // 31))
        return Image.frombytes("RGB", (w, h), bytes(px))
    return Image.frombytes("RGB", (w, h), raw[:w * h * 3])


def take_shots(a, t, desc):
    """screenshots of loop t: the port rerun and the control run, side by side in tas/shots/loop_<t>.png"""
    from PIL import Image, ImageChops
    os.makedirs(SHOTS, exist_ok=True)
    for f in glob.glob(os.path.join(REPO, "obj_ps2", "frame_*.ppm")) + glob.glob(os.path.join(SHOTS, "redux_*")):
        os.remove(f)
    print("screenshots of loop %d: the port again and the Redux control run" % t, flush=True)
    # the control run only depends on the loop, the tables and redux_replay.lua: its screens are kept by those
    key = hashlib.sha1(str(t).encode())
    for f in ("pads.bin", "raw.bin", "time.bin", "MovieSaveRam.bin"):
        key.update(open(os.path.join(os.path.expanduser(a.tables), f), "rb").read())
    key.update(open(os.path.join(REPO, "tools", "port", "tas", "redux_replay.lua"), "rb").read())
    cache = os.path.join(SHOTS, "cache", key.hexdigest())
    rx = None if os.path.isdir(cache) else redux(os.path.expanduser(a.tables), t)
    if rx is None:
        print("screenshots: the control run's from %s" % os.path.relpath(cache, REPO), flush=True)
        for f in glob.glob(os.path.join(cache, "*")):
            shutil.copy(f, SHOTS)
    cmd = [sys.executable, os.path.abspath(__file__), "--no-shots", "--no-link", "--shot", str(t), "--last", str(t + 2),
           "--tables", a.tables, "--ref", a.ref, "--from", str(a.start), "--seconds", str(a.seconds)]
    for spec in a.ignore + ["%s@%d-%d" % (n, t, t + 2) for n in FIELDS.values()]:  # the run's own desync again
        cmd += ["--ignore", spec]
    subprocess.run(cmd, stdout=subprocess.DEVNULL)
    if rx is not None:
        rx.wait(900)
        if os.path.exists(os.path.join(SHOTS, "redux_%d.raw" % t)):
            os.makedirs(cache, exist_ok=True)
            for f in glob.glob(os.path.join(SHOTS, "redux_%d.*" % t)) + glob.glob(os.path.join(SHOTS, "redux_%d.*" % (t + 1))):
                shutil.copy(f, cache)
    compose(t, desc)


def compose(t, desc):
    from PIL import Image, ImageChops
    dumps = sorted(glob.glob(os.path.join(REPO, "obj_ps2", "frame_*.ppm")))
    if not dumps or not os.path.exists(os.path.join(SHOTS, "redux_%d.raw" % t)):
        print("screenshots: missing (port dump %s, Redux %s)" % (bool(dumps), os.path.exists(
            os.path.join(SHOTS, "redux_%d.raw" % t))))
        return
    ps1 = ps1_image(t)
    port = Image.open(dumps[0]).convert("RGB")
    port = port.resize((ps1.width, ps1.width * port.height // port.width), Image.NEAREST)
    h = max(ps1.height, port.height)
    out = Image.new("RGB", (ps1.width * 3, h))
    out.paste(ps1, (0, 0))
    out.paste(port, (ps1.width, 0))
    diff = ImageChops.difference(ps1.crop((0, 0, ps1.width, h)), port.crop((0, 0, ps1.width, h))).convert("L")
    out.paste(diff.point(lambda v: 255 if v > 24 else 0).convert("RGB"), (ps1.width * 2, 0))
    os.makedirs(os.path.join(REPO, "tas", "shots"), exist_ok=True)
    path = os.path.join(REPO, "tas", "shots", "loop_%d.png" % t)
    out.save(path)
    open(path[:-4] + ".txt", "w").write(desc)
    print("screenshots: %s (PS1 | port | difference over 24)" % os.path.relpath(path, REPO))


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
    ap.add_argument("--no-shots", action="store_true")
    ap.add_argument("--show", action="store_true", help="the emulator windows on the desktop")
    ap.add_argument("--shot", type=int, default=0)
    a = ap.parse_args()
    if a.show:
        os.environ["MGS_SHOW"] = "1"
    rules = parse_ignore(a.ignore)
    tables = os.path.expanduser(a.tables)

    if not a.no_link:
        env = dict(os.environ, MGS_MC_IMAGE=os.path.join(tables, "MovieSaveRam.bin"),
                   MGS_TAS_PADS=os.path.join(tables, "pads.bin"), MGS_TAS_RAW=os.path.join(tables, "raw.bin"),
                   MGS_TAS_TIME=os.path.join(tables, "time.bin"))
        if subprocess.run([sys.executable, os.path.join(REPO, "build", "link_ps2.py")], env=env,
                          stdout=subprocess.DEVNULL).returncode:
            sys.exit("link_ps2.py failed")

    shot = os.path.join(REPO, "obj_ps2", "tas_shot.txt")  # read by the port at startup (tas_replay.c)
    if a.shot:
        open(shot, "w").write("%d\n" % a.shot)
    elif os.path.exists(shot):
        os.remove(shot)

    ref_path = os.path.expanduser(a.ref)
    ref = {}
    for line in (lzma.open(ref_path, "rt") if ref_path.endswith(".xz") else open(ref_path)):
        f = line.split()
        if len(f) >= 14:
            ref[int(f[1])] = f
    fix_clock(ref)
    print("reference: %d loops; comparing from loop %d" % (len(ref), a.start), flush=True)

    if os.path.exists(TRACE):
        os.remove(TRACE)
    log = open(os.path.join(REPO, "obj_ps2", "run_port.log"), "w")
    run = subprocess.Popen([OFFSCREEN, sys.executable, "-u", PCSX2_RUN, os.path.join(REPO, "obj_ps2", "mgs_ps2.iso"),
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
            if a.shot:
                time.sleep(3)  # the frame dump is still being written to host: (a cut one at loop 11,444)
            run.send_signal(signal.SIGTERM)  # pcsx2_run.py closes PCSX2
            run.wait(30)
        log.close()

    for name, (t, d) in sorted(ignored_first.items(), key=lambda x: x[1][0]):
        print("ignored: %-20s from loop %d: %s" % (name, t, d))
    if desync is None:
        why = "reached loop %d" % a.last if a.last and last_t >= a.last else "PCSX2 ended (see obj_ps2/run_port.log)"
        print("in sync to loop %d: %s" % (last_t, why))
        return 0 if a.last and last_t >= a.last else 1
    lines = ["DESYNC %-20s at loop %d (%s, movie %s, frame %s): %s" % (name, t, r[6], when(r[0]), r[0], d)
             for name, (t, r, d) in first.items()]
    print("\n".join(lines), flush=True)
    if not a.no_shots:
        take_shots(a, desync, "\n".join(lines) + "\n")
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
