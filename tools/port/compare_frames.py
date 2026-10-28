#!/usr/bin/env python3
"""Compares the port's GS renderer with the PS1 game in DuckStation (software renderer, the reference),
frame by frame, with the PS1's exact GPU commands.

1. DuckStation runs the Integral disc (disc 1's CHD in ps1-original/) and tools/port/gdb/capture_ps1.py captures
   frames of a stage (--stage, default "opening"; frames are game loops from the end of its load): the VRAM
   before the frame, its GPU commands, and the VRAM after.
2. The port in PCSX2 (obj_ps2/mgs_ps2.iso) replays them (port/src/capture_ps2.c): the VRAM before loaded,
   the commands drawn by the GS renderer, the VRAM written back.
   With --live instead, the port plays the stage itself and its own frame N (the same game loop) is
   captured: the whole game (logic, GTE, effects) against the PS1, not just the renderer. Cutscenes are
   clocked by the demo stream (FS_StreamGetTick: voice audio or vertical blanks), so the port replays the
   PS1's clock loop by loop (ps1_ticks.txt), starts the stream at the PS1's loop and takes its double-buffer
   parity: its frames line up with the PS1's. Run without --skip-ps1 after changing --frames' range: the
   ticks are recorded only up to the last frame captured.
3. Per frame, obj_ps2/cap/ gets cmp[live]_<N>.png: the frame's draw area (its last E3/E4), PS1 | PS2 | difference
   (white = differs), and cmp[live]_<N>_vram.png: all of VRAM, PS1 above PS2, then the difference. The report
   counts differing pixels (bit 15, the mask bit, separately).

    python3 tools/port/compare_frames.py --frames 100,400,700 [--stage opening] [--live] [--skip-ps1] [--skip-ps2]
"""
import argparse
import os
import signal
import struct
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
OUT = os.path.join(REPO, "obj_ps2")
CAP = os.path.join(OUT, "cap")
ISO = os.path.join(OUT, "mgs_ps2.iso")
CUE = os.path.join(REPO, "ps1-original", "Metal Gear Solid - Integral (Japan, Asia) (En,Ja)",
                   "Metal Gear Solid - Integral (Japan, Asia) (En,Ja) (Disc 1).chd")
DUCKSTATION = os.path.expanduser("~/Downloads/DuckStation-x64.AppImage")
PCSX2_RUN = os.path.join(REPO, "..", "silent-hill-1-ps2-port", "tools", "port", "pcsx2_run.py")
sys.path.insert(0, os.path.join(REPO, "..", "silent-hill-1-ps2-port", "tools", "port", "gdb"))
import warp_sweep  # noqa: E402  (DuckStation settings patching: GDB server, unlimited speed, muted)


def capture_ps1(frames, stage):
    backup = warp_sweep.patch_settings()
    ds = None
    try:
        ds = subprocess.Popen([DUCKSTATION, "-batch", "-fastboot", "-nofullscreen", "--", CUE],
                              stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, stdin=subprocess.DEVNULL,
                              start_new_session=True)  # own process group: the AppImage doesn't forward signals
        if not warp_sweep.wait_port(2345, 30):
            sys.exit("DuckStation's GDB server didn't start")
        time.sleep(1)
        env = dict(os.environ, CAP_FRAMES=",".join(map(str, frames)), CAP_OUT=CAP, CAP_STAGE=stage)
        out = subprocess.run(["gdb-multiarch", "-q", "-batch", "-ex", "set architecture mips:3000",
                              "-ex", "target remote localhost:2345", "-x", os.path.join(HERE, "gdb", "capture_ps1.py")],
                             env=env, capture_output=True, text=True, timeout=1800, stdin=subprocess.DEVNULL)
        print("\n".join(l for l in (out.stdout + out.stderr).splitlines() if "capture:" in l or "rror" in l))
    finally:
        if ds:
            for sig in (signal.SIGTERM, signal.SIGKILL):
                try:
                    os.killpg(ds.pid, sig)
                    ds.wait(5)
                    break
                except (ProcessLookupError, subprocess.TimeoutExpired):
                    pass
        os.replace(backup, warp_sweep.SETTINGS)


def run_ps2(frames, live, stage):
    path = os.path.join(OUT, "capture.txt")
    if live:
        open(path, "w").write("stage=%s ticks " % stage + " ".join("live=%d" % f for f in frames) + "\n")
    else:
        open(path, "w").write(" ".join("replay=%d" % f for f in frames) + "\n")
    try:
        out = subprocess.run([sys.executable, PCSX2_RUN, "--seconds", "600", "--until", "capture: all frames done", ISO],
                             capture_output=True, text=True).stdout
    finally:
        os.remove(path)
    print("\n".join(l.split("] ", 1)[-1] for l in out.splitlines()
                    if "capture:" in l or "TLB" in l or l.startswith("pcsx2_run:")))


def load_vram(path):
    return struct.unpack("<%dH" % (1024 * 512), open(path, "rb").read())


def draw_area(n, side="ps1"):
    """The last E3/E4 (drawing area) of the frame's commands: x0, y0, x1, y1 inclusive."""
    data, pos, area = open(os.path.join(CAP, "%s_%d_gp0.bin" % (side, n)), "rb").read(), 0, [0, 0, 319, 239]
    while pos + 4 <= len(data):
        (cnt,) = struct.unpack_from("<I", data, pos)
        for w in struct.unpack_from("<%dI" % cnt, data, pos + 4):
            if w >> 24 in (0xE3, 0xE4):
                i = 0 if w >> 24 == 0xE3 else 2
                area[i], area[i + 1] = w & 0x3FF, (w >> 10) & 0x1FF
            if w >> 24 not in range(0xE1, 0xE7):
                break  # only state words at a packet's start count
        pos += 4 + 4 * cnt
    return area


def rgb(c):
    return ((c & 31) << 3, ((c >> 5) & 31) << 3, ((c >> 10) & 31) << 3)


def save(path, w, h, pixels):
    from PIL import Image
    im = Image.new("RGB", (w, h))
    im.putdata(pixels)
    im.save(path)


def packet_count(path):
    data, pos, n = open(path, "rb").read(), 0, 0
    while pos + 4 <= len(data):
        pos += 4 + 4 * struct.unpack_from("<I", data, pos)[0]
        n += 1
    return n


def compare(n, side):
    a = load_vram(os.path.join(CAP, "ps1_%d_vram.bin" % n))
    b = load_vram(os.path.join(CAP, "%s_%d_vram.bin" % (side, n)))
    # Each side's own draw area: the two can be drawing different buffers of the double buffer.
    x0, y0, x1, y1 = draw_area(n)
    bx0, by0 = draw_area(n, side)[:2] if side == "ps2" else (x0, y0)
    w, h = x1 - x0 + 1, y1 - y0 + 1
    rows, dd, dm = [], 0, 0
    for y in range(h):
        pa, pb, pd = [], [], []
        for x in range(w):
            ca, cb = a[(y0 + y) * 1024 + x0 + x], b[(by0 + y) * 1024 + bx0 + x]
            diff = (ca ^ cb) & 0x7FFF
            dd += diff != 0
            dm += (ca ^ cb) >> 15
            pa.append(rgb(ca))
            pb.append(rgb(cb))
            pd.append((255, 255, 255) if diff else (0, 0, 0))
        rows.append(pa + pb + pd)
    tag = "" if side == "ps2r" else "live"
    save(os.path.join(CAP, "cmp%s_%d.png" % (tag, n)), 3 * w, h, [p for r in rows for p in r])
    vd = sum(1 for i in range(1024 * 512) if (a[i] ^ b[i]) & 0x7FFF)
    save(os.path.join(CAP, "cmp%s_%d_vram.png" % (tag, n)), 1024, 1536,
         [rgb(c) for c in a] + [rgb(c) for c in b] +
         [(255, 255, 255) if (a[i] ^ b[i]) & 0x7FFF else (0, 0, 0) for i in range(1024 * 512)])
    extra = ""
    if side == "ps2":
        extra = "; packets: PS1 %d (with image transfers), PS2 %d" % (
            packet_count(os.path.join(CAP, "ps1_%d_gp0.bin" % n)), packet_count(os.path.join(CAP, "ps2_%d_gp0.bin" % n)))
    if (bx0, by0) != (x0, y0):
        extra += "; PS2 drew the other buffer (%d,%d): VRAM totals not comparable" % (bx0, by0)
    print("frame %d: draw area %d,%d-%d,%d: %d of %d pixels differ (bit 15: %d); VRAM: %d of 524288%s" % (
        n, x0, y0, x1, y1, dd, w * h, dm, vd, extra))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--frames", required=True)
    ap.add_argument("--stage", default="opening")
    ap.add_argument("--live", action="store_true", help="the port's own frames instead of a replay")
    ap.add_argument("--skip-ps1", action="store_true", help="reuse the DuckStation captures")
    ap.add_argument("--skip-ps2", action="store_true", help="reuse the PCSX2 captures")
    args = ap.parse_args()
    frames = sorted(int(x) for x in args.frames.split(","))
    os.makedirs(CAP, exist_ok=True)
    if not args.skip_ps1:
        capture_ps1(frames, args.stage)
    if not args.skip_ps2:
        run_ps2(frames if args.live else [f for f in frames if os.path.exists(os.path.join(CAP, "ps1_%d_gp0.bin" % f))],
                args.live, args.stage)
    side = "ps2" if args.live else "ps2r"
    for f in frames:
        if all(os.path.exists(os.path.join(CAP, n % f)) for n in ("ps1_%d_vram.bin", side + "_%d_vram.bin")):
            compare(f, side)
        else:
            print("frame %d: not captured" % f)


if __name__ == "__main__":
    main()
