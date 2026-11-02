#!/usr/bin/env python3
"""~/emu/tas/timeline.log (timeline.lua) to timeline.bin next to it: 8 bytes per loop: the PS1's stream actor at that
trace line (u32: 0 none, 1 Act, 2 Act2, 3 being destroyed, GV_DestroyActor's stand-in act), and jimctrl.c's counter
the loop before the line, if it moved (s32, else -1)."""
import os
import struct

D = os.path.expanduser("~/emu/tas")
K = {"80037820": 1, "800377ec": 2, "80015164": 3}
out = bytearray()
last = -1
for line in open(os.path.join(D, "timeline.log"), errors="ignore"):
    f = line.split()
    if len(f) == 11 and f[0].isdigit():
        t = int(f[0])
        out.extend(b"\0" * ((t + 1) * 8 - len(out)))
        c = int(f[10])
        struct.pack_into("<Ii", out, t * 8, K.get(f[1], 0) if int(f[3]) else 0, c if f[9] == "2" and c != last else -1)
        last = c
open(os.path.join(D, "timeline.bin"), "wb").write(out)
print(len(out) // 8, "loops")
