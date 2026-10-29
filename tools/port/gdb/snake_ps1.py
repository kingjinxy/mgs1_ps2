"""gdb script: plays the PS1 game in DuckStation up to the dock's gameplay with no further input, and logs
Snake's position and status (GM_PlayerPosition, GM_PlayerStatus) every 30 game loops for 930 loops: the PS1
reference for the port's MGS_DEBUG_PLAYER log (port/src/hal_game.c). Presses are written to mts's pad state
(pad_800C14E0) at the start of GV_UpdatePadSystem: START, START, Circle, Circle cycled on the title, then START
while Snake's status is non-zero (briefing, codec) until the dock's codec call is over.

Run with DuckStation's GDB server (as tools/port/compare_frames.py starts it):
    gdb-multiarch -q -batch -ex "set architecture mips:3000" -ex "target remote localhost:2345" -x tools/port/gdb/snake_ps1.py
"""
import struct, gdb
inf = gdb.selected_inferior()
r32 = lambda a: struct.unpack("<I", bytes(inf.read_memory(a, 4)))[0]
reg = lambda n: int(gdb.parse_and_eval("$" + n)) & 0xFFFFFFFF
PAD = 0x800C14E0; UPD = 0x8001682C; TIME = 0x800AB330; POS = 0x800ABA10; STAT = 0x800ABA50; NEWLOADER = 0x8002E460
gdb.execute("set pagination off")
gdb.Breakpoint("*0x%08X" % UPD, internal=True)
gdb.Breakpoint("*0x%08X" % NEWLOADER, internal=True)
stage, n, idle_from, last, seen_codec, zero_run = "", 0, None, -1, False, 0
MENU = [0x0800, 0x0800, 0x0020, 0x0020]
while True:
    gdb.execute("continue", to_string=True)
    if reg("pc") == NEWLOADER:
        stage = bytes(inf.read_memory(reg("a0"), 16)).split(b"\0")[0].decode()
        print("snake: stage %s at loop %d" % (stage, r32(TIME)), flush=True)
        n = 0
        continue
    n += 1
    t = r32(TIME)
    x, y, z = struct.unpack("<hhh", bytes(inf.read_memory(POS, 6)))
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
            print("snake: idle from loop %d" % t, flush=True)
        elif status != 0 and n % 50 < 4:
            held = 0x0800
    if held:
        inf.write_memory(PAD, struct.pack("<BBH", 0, 1, ~held & 0xFFFF))
    if idle_from is not None and (t - idle_from) // 30 != last:
        last = (t - idle_from) // 30
        print("snake: +%d loops pos %d %d %d status %08x" % (t - idle_from, x, y, z, status), flush=True)
        if t - idle_from > 900:
            break
    if t > 9000:
        print("snake: gave up (stage %s, status %08x)" % (stage, status)); break
gdb.execute("kill")
