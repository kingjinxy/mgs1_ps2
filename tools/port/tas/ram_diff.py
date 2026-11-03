#!/usr/bin/env python3
"""ram_diff.py PS1_RAM PORT_RAM [OVL]: the game's data symbols that differ between the PS1 (ram_dump.lua: 2 MB of main
RAM at a loop) and the port (host:tas_ramdump.txt -> obj_ps2/tas_ram.bin: a u32 base, then .data to _end) at the same
loop. Symbols are matched by name: the PS1's from obj/asm_OVL_lhs.map (resident ones, and the overlay's), the port's
from obj_ps2/mgs.elf; each is compared over the shorter of its two sizes (up to the next symbol). Words that are
pointers on both sides are skipped (they differ by layout).

usage: ram_diff.py ~/emu/tas/ram_47498.bin obj_ps2/tas_ram.bin s10a"""
import bisect, os, re, struct, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
ps1 = open(sys.argv[1], 'rb').read()
port = open(sys.argv[2], 'rb').read()
ovl = sys.argv[3] if len(sys.argv) > 3 else 's07b'
pbase = struct.unpack_from('<I', port, 0)[0]; port = port[4:]

m = {}
for l in open(os.path.join(ROOT, 'obj', 'asm_%s_lhs.map' % ovl), errors='ignore'):
    p = l.split()
    if len(p) == 2 and re.match(r'^[0-9A-F]{8}$', p[0]):
        m.setdefault(p[1], int(p[0], 16))
pa = sorted(set(m.values()))
nm = subprocess.run(['/home/alex/ps2dev/ee/bin/mips64r5900el-ps2-elf-nm', '-n', '-S',
                     os.path.join(ROOT, 'obj_ps2', 'mgs.elf')], capture_output=True, text=True).stdout
q = {}
for l in nm.split('\n'):
    p = l.split()
    if len(p) == 4 and p[2] in 'dDbBrR':
        q[p[3]] = (int(p[0], 16), int(p[1], 16))
DATA_LO = 0x8009D2DC  # the PS1's .data: code before it isn't compared
def ptr(v): return 0x80000000 <= v < 0x80200000 or pbase - 0x200000 <= v < pbase + len(port) + 0x1000000
out = []
for name, a in m.items():
    if a < DATA_LO or name not in q:
        continue
    i = bisect.bisect_right(pa, a)
    size = min((pa[i] if i < len(pa) else a + 4) - a, q[name][1], 4096)
    pa_ = q[name][0] - pbase
    if size <= 0 or not (0 <= pa_ and pa_ + size <= len(port)) or a - 0x80000000 + size > len(ps1):
        continue
    x = ps1[a - 0x80000000:a - 0x80000000 + size]; y = port[pa_:pa_ + size]
    diffs = []
    for o in range(0, size - size % 4, 4):
        u, v = struct.unpack_from('<I', x, o)[0], struct.unpack_from('<I', y, o)[0]
        if u != v and not (ptr(u) and ptr(v)):
            diffs.append((o, u, v))
    if diffs:
        out.append((a, name, size, diffs))
for a, name, size, diffs in sorted(out):
    print('%08X %-32s %5d bytes, %d words differ: %s' % (a, name, size, len(diffs),
          ' '.join('+%x %08x/%08x' % d for d in diffs[:6])))
print('%d symbols differ' % len(out))
