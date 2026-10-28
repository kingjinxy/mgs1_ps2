"""gdb script (run by tools/port/compare_frames.py) capturing frames of a stage from the PS1 game in
DuckStation. Frames are game loops (GV_Time) from the end of the stage's load (CAP_STAGE, default "opening";
FS_LoadStageComplete, from the loader's Die: load times differ between machines). Not every loop draws (no
DrawOTag), so frame N is captured at the first DrawOTag of loop N or later. For each frame in CAP_FRAMES,
writes to CAP_OUT:
  ps1_<N>_before.bin  the 1024x512 VRAM before the frame's first GPU call (previous frame drawn)
  ps1_<N>_gp0.bin     every GPU command of the frame in order (u32 word count, then the words): the
                      ordering table's packets, PutDrawEnv's packet, and LoadImage (A0 + its pixels),
                      MoveImage (80) and ClearImage (02) as GP0 commands
  ps1_<N>_vram.bin    the VRAM after the frame's drawing (at the next frame's first GPU call)

A frame is the GPU calls after the previous frame's DrawOTag, up to and including its own. VRAM is read
by calling the game's own DrawSync + StoreImage from gdb, in 64-line chunks through a scratch RAM area
whose bytes are restored after. Addresses: obj/asm.map (the Integral executable).

Also ps1_ticks.txt: the demo stream's clock as the PS1 ran it, for the port to replay (capture_ps2.c,
--live): GV_Clock at the load's end, the loop of FS_StreamTickStart, then per loop the tick kojo/demothrd.c's
ActStream got from FS_StreamGetTick. Cutscenes follow that clock (the voice stream's SPU counter, or vertical
blanks), not frames.
"""
import os
import struct

import gdb

FRAMES = sorted(int(x) for x in os.environ["CAP_FRAMES"].split(","))
OUT = os.environ["CAP_OUT"]
STAGE = os.environ.get("CAP_STAGE", "opening")

NEWLOADER = 0x8002E460
DRAWOTAG = 0x8008FE58
PUTDRAWENV = 0x8008FEC8
LOADIMAGE = 0x8008FB10
MOVEIMAGE = 0x8008FBD0
CLEARIMAGE = 0x8008F9E8
STOREIMAGE = 0x8008FB70
DRAWSYNC = 0x8008F864
GV_TIME = 0x800AB330
GV_CLOCK = 0x800AB920
LOAD_END = 0x80023804     # FS_LoadStageComplete
TICK_START = 0x800243D8   # FS_StreamTickStart
TICK_RET = 0x80079680     # ActStream, after its FS_StreamGetTick call: v0 = the tick
SCRATCH = 0x80100000       # 16-byte RECT + 1024x64x2 bytes, restored after each chunk

REGS = ["at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
        "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "s8", "ra",
        "lo", "hi", "pc"]

inf = gdb.selected_inferior()


def r32(addr):
    return struct.unpack("<I", bytes(inf.read_memory(addr, 4)))[0]


def reg(name):
    return int(gdb.parse_and_eval("$" + name)) & 0xFFFFFFFF


def call(fn, args):
    """Calls a PS1 function at a breakpoint: returns to the current PC (a breakpoint address)."""
    saved = {r: reg(r) for r in REGS}
    here = saved["pc"]
    gdb.execute("set $sp = %d" % ((saved["sp"] - 64) & 0xFFFFFFFF))
    for i, a in enumerate(args):
        gdb.execute("set $a%d = %d" % (i, a))
    gdb.execute("set $ra = %d" % here)
    gdb.execute("set $pc = %d" % fn)
    gdb.execute("continue", to_string=True)
    if reg("pc") != here:
        raise RuntimeError("call to %08X stopped at %08X" % (fn, reg("pc")))
    for r, v in saved.items():
        gdb.execute("set $%s = %d" % (r, v))


def read_vram():
    call(DRAWSYNC, [0])
    data = bytearray()
    for chunk in range(8):
        size = 16 + 1024 * 64 * 2
        original = bytes(inf.read_memory(SCRATCH, size))
        inf.write_memory(SCRATCH, struct.pack("<hhhh", 0, chunk * 64, 1024, 64))
        call(STOREIMAGE, [SCRATCH, SCRATCH + 16])
        call(DRAWSYNC, [0])
        data += bytes(inf.read_memory(SCRATCH + 16, 1024 * 64 * 2))
        inf.write_memory(SCRATCH, original)
    return bytes(data)


def rect(addr):
    return struct.unpack("<hhhh", bytes(inf.read_memory(addr, 8)))


def cstr(addr):
    s = bytes(inf.read_memory(addr, 32))
    return s.split(b"\0")[0].decode("latin-1")


gdb.execute("set pagination off")
# Only NewLoader stops the emulator until the stage loads.
load_bp = gdb.Breakpoint("*0x%08X" % NEWLOADER, internal=True)
while True:
    gdb.execute("continue", to_string=True)
    name = cstr(reg("a0"))
    print("capture: stage %s (GV_Time %d, GV_Clock %d)" % (name, r32(GV_TIME), r32(GV_CLOCK)), flush=True)
    if name == STAGE:
        break

for addr in (DRAWOTAG, PUTDRAWENV, LOADIMAGE, MOVEIMAGE, CLEARIMAGE, TICK_START, TICK_RET, LOAD_END):
    gdb.Breakpoint("*0x%08X" % addr, internal=True)

base = None           # GV_Time at the load's end (None while loading)
done = set()
open_frame = None     # frame being recorded (its first GPU call seen)
close_frame = None    # frame whose final VRAM is read at the next GPU call
packets = []
pending_env = None    # DRAWENV* from the last PutDrawEnv, its packet not yet recorded
ticks = open(os.path.join(OUT, "ps1_ticks.txt"), "w")

while len(done) < len(FRAMES):
    gdb.execute("continue", to_string=True)
    pc = reg("pc")
    frame = r32(GV_TIME) - base if base is not None else -1  # game loops since the load's end
    if pc == NEWLOADER:
        print("capture: stage %s: ending (frame %d)" % (cstr(reg("a0")), frame), flush=True)
        break

    if pc == LOAD_END:
        base = r32(GV_TIME)
        ticks.write("clock %d\n" % r32(GV_CLOCK))
        print("capture: load end (GV_Time %d)" % base, flush=True)
        continue
    if pc == TICK_START and base is not None:
        ticks.write("start %d\n" % frame)
        continue
    if pc == TICK_RET and base is not None:
        ticks.write("%d %d\n" % (frame, reg("v0")))
        continue

    if pending_env is not None:
        # The DRAWENV packet built by the previous PutDrawEnv (tag at +1Ch, words at +20h).
        n = r32(pending_env + 0x1C) >> 24
        packets.append([r32(pending_env + 0x20 + 4 * i) for i in range(n)])
        pending_env = None

    if close_frame is not None:
        open(os.path.join(OUT, "ps1_%d_vram.bin" % close_frame), "wb").write(read_vram())
        print("capture: frame %d done" % close_frame, flush=True)
        done.add(close_frame)
        close_frame = None

    pending = [f for f in FRAMES if f not in done and f != close_frame and f <= frame]
    if open_frame is None and pending:
        open_frame, packets = pending[0], []
        open(os.path.join(OUT, "ps1_%d_before.bin" % open_frame), "wb").write(read_vram())

    if pc == DRAWOTAG:
        if open_frame is not None:
            addr, count = reg("a0") & 0xFFFFFF, 0
            while addr != 0xFFFFFF and count < 200000:
                hdr = r32(0x80000000 | addr)
                n = hdr >> 24
                if n:
                    packets.append(list(struct.unpack("<%dI" % n, bytes(inf.read_memory(0x80000000 | (addr + 4), 4 * n)))))
                addr = hdr & 0xFFFFFF
                count += 1
            with open(os.path.join(OUT, "ps1_%d_gp0.bin" % open_frame), "wb") as f:
                for words in packets:
                    f.write(struct.pack("<I", len(words)))
                    f.write(struct.pack("<%dI" % len(words), *words))
            print("capture: frame %d: loop %d, %d packets (GV_Clock %d)" % (open_frame, frame, len(packets), r32(GV_CLOCK)), flush=True)
            close_frame, open_frame = open_frame, None
        continue

    if open_frame is None:
        continue
    if pc == PUTDRAWENV:
        pending_env = reg("a0")
    elif pc == LOADIMAGE:
        x, y, w, h = rect(reg("a0"))
        pixels = bytes(inf.read_memory(reg("a1"), w * h * 2))
        pixels += b"\0" * (len(pixels) & 2)
        packets.append([0xA0000000, (y << 16) | (x & 0xFFFF), (h << 16) | (w & 0xFFFF)] +
                       list(struct.unpack("<%dI" % (len(pixels) // 4), pixels)))
    elif pc == MOVEIMAGE:
        x, y, w, h = rect(reg("a0"))
        packets.append([0x80000000, (y << 16) | (x & 0xFFFF), (reg("a2") << 16) | (reg("a1") & 0xFFFF),
                        (h << 16) | (w & 0xFFFF)])
    elif pc == CLEARIMAGE:
        x, y, w, h = rect(reg("a0"))
        packets.append([0x02000000 | ((reg("a3") & 0xFF) << 16) | ((reg("a2") & 0xFF) << 8) | (reg("a1") & 0xFF),
                        (y << 16) | (x & 0xFFFF), (h << 16) | (w & 0xFFFF)])

ticks.close()
print("capture: all frames done", flush=True)
gdb.execute("kill")
