"""(tools/port/match_asm_funcs.py; run from the repo root.)
For each s03d INCLUDE_ASM function: its call sequence (jal targets named from obj/asm.map, overlay-local ones
as 'local'), its length; against every function in obj/**/*.asm (compiler output), ranked by call-sequence
similarity and length."""
import glob, re, difflib, os, sys
names = {}
for l in open('obj/asm.map'):
    p = l.split()
    if len(p) == 2 and re.match(r'^[0-9A-F]{8}$', p[0]):
        names.setdefault(int(p[0], 16), p[1])
def s03d_funcs():
    out = {}
    for f in sorted(glob.glob('asm/overlays/%s/*.s' % (sys.argv[1] if len(sys.argv) > 1 else 's03d'))):
        words = [int(m, 16) for m in re.findall(r'dw 0x([0-9A-F]{8})', open(f).read())]
        calls = []
        for w in words:
            if w >> 26 == 3:
                t = 0x80000000 | ((w & 0x3FFFFFF) << 2)
                calls.append(names.get(t, 'local'))
        out[os.path.basename(f)[:-2]] = (calls, len(words))
    return out
def asm_funcs():
    out = {}
    for f in glob.glob('obj/**/*.asm', recursive=True):
        cur = None
        for l in open(f, errors='replace'):
            m = re.match(r'\t\.ent\t(\S+)', l)
            if m: cur = m.group(1); out[(f, cur)] = [[], 0]; continue
            if cur is None: continue
            if l.startswith('\t.end'): cur = None; continue
            if l.startswith('\t') and not l.startswith('\t.') and not l.startswith('\t#'):
                out[(f, cur)][1] += 1
                m = re.match(r'\tjal\t(\S+)', l)
                if m: out[(f, cur)][0].append(m.group(1))
    return out
S, A = s03d_funcs(), asm_funcs()
import sys
OVL = sys.argv[1] if len(sys.argv) > 1 else "s03d"
for name, (calls, n) in S.items():
    best = []
    for (f, fn), (c2, n2) in A.items():
        if 'overlays/' + OVL in f: continue
        cs = [x if x != 'local' else '?' for x in calls]
        c2n = [x if x in names.values() else '?' for x in c2]
        r = difflib.SequenceMatcher(None, cs, c2n).ratio() if (cs or c2n) else 0
        lr = min(n, n2) / max(n, n2) if max(n, n2) else 0
        best.append((r * 0.7 + lr * 0.3, r, n2, f.replace('obj/', ''), fn))
    best.sort(reverse=True)
    print('%s  %d words, %d calls' % (name, n, len(calls)))
    for b in best[:2]:
        print('    %.2f calls %.2f %d lines  %s %s' % b)
