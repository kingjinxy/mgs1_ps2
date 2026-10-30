"""gdb script: how many game loops Snake takes to react to the stick on the PS1 (TAS Testing Plan: Snake turns a
loop early in the port at loop 1012). Plays the PS1 game in DuckStation to the dock's gameplay as snake_ps1.py
does, then from loop L (60 loops after Snake is idle) holds a d-pad direction, written to mts's pad state at the
start of GV_UpdatePadSystem, and logs at each pad update (the start of loop N): the previous loop's
GV_PadData[0].dir, Snake's CONTROL.turn/rot, his state function and turn countdown (field_A38_local_data).
If turn changes at loop L+1's line, Snake used the stick in the loop it was read in (no latency).

Run as tools/port/gdb/snake_ps1.py (DuckStation's GDB server on localhost:2345); TURN_DIR: the button
(hex, default 4000: down).
"""
import os, re, struct, gdb
inf = gdb.selected_inferior()
r32 = lambda a: struct.unpack("<I", bytes(inf.read_memory(a, 4)))[0]
s16 = lambda a: struct.unpack("<h", bytes(inf.read_memory(a, 2)))[0]
reg = lambda n: int(gdb.parse_and_eval("$" + n)) & 0xFFFFFFFF
PAD = 0x800C14E0; UPD = 0x8001682C; TIME = 0x800AB330; POS = 0x800ABA10; STAT = 0x800ABA50; NEWLOADER = 0x8002E460
PADDATA = 0x800B05C0; CTRL = 0x800AB9F4
TURN = int(os.environ.get("TURN_DIR", "4000"), 16)
names = {}
try:
    for l in open("obj/asm.map"):
        m = re.match(r"\s+([0-9A-F]{8})\s+(\S+)$", l)
        if m:
            names[int(m.group(1), 16)] = m.group(2)
except OSError:
    pass
gdb.execute("set pagination off")
gdb.Breakpoint("*0x%08X" % UPD, internal=True)
gdb.Breakpoint("*0x%08X" % NEWLOADER, internal=True)
stage, n, idle_from, seen_codec, zero_run = "", 0, None, False, 0
MENU = [0x0800, 0x0800, 0x0020, 0x0020]
while True:
    gdb.execute("continue", to_string=True)
    if reg("pc") == NEWLOADER:
        stage = bytes(inf.read_memory(reg("a0"), 16)).split(b"\0")[0].decode()
        print("turn: stage %s at loop %d" % (stage, r32(TIME)), flush=True)
        n = 0
        continue
    n += 1
    t = r32(TIME)
    status = r32(STAT)
    held = 0
    if stage in ("init", "title", "opening", ""):
        if n % 45 < 4:
            held = MENU[(n // 45) % 4]
    elif idle_from is None:
        seen_codec = seen_codec or (stage == "s00a" and status != 0)
        zero_run = zero_run + 1 if status == 0 else 0
        if seen_codec and zero_run >= 30:
            idle_from = t
            print("turn: idle from loop %d" % t, flush=True)
        elif status != 0 and n % 50 < 4:
            held = 0x0800
    else:
        L = idle_from + 60
        if t >= L:
            held = TURN
        if L - 3 <= t <= L + 6:
            c = r32(CTRL)
            work = c - 0x20
            fn = r32(work + 0x9B8)
            print("turn: loop %d%s prev dir %d | turn %d rot %d | %s frame %d A38 %d"
                  % (t, " (press from here)" if t == L else "", s16(PADDATA + 8), s16(c + 0x4E), s16(c + 0xA),
                     names.get(fn, hex(fn)), s16(work + 0x9BC), s16(work + 0xA38)), flush=True)
        if t > L + 6:
            break
    if held:
        inf.write_memory(PAD, struct.pack("<BBH", 0, 1, ~held & 0xFFFF))
    if t > 9000:
        print("turn: gave up (stage %s, status %08x)" % (stage, status)); break
gdb.execute("kill")
