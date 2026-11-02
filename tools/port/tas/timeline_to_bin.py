#!/usr/bin/env python3
"""~/emu/tas/timeline.log (timeline.lua) to timeline.bin next to it: a byte per loop, the PS1's stream actor at that
trace line: 0 none, 1 Act, 2 Act2, 3 being destroyed (GV_DestroyActor's stand-in act)."""
import os

D = os.path.expanduser("~/emu/tas")
K = {"80037820": 1, "800377ec": 2, "80015164": 3}
out = bytearray()
for line in open(os.path.join(D, "timeline.log"), errors="ignore"):
    f = line.split()
    if len(f) == 9 and f[0].isdigit():
        t = int(f[0])
        out.extend(b"\0" * (t + 1 - len(out)))
        out[t] = K.get(f[1], 0) if int(f[3]) else 0
open(os.path.join(D, "timeline.bin"), "wb").write(out)
print(len(out), "loops")
