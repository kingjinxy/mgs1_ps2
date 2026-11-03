#!/usr/bin/env python3
"""mips2c.py OVL: each INCLUDE_ASM stub of an overlay as exact-behaviour C for the port (MGS_PORT), one file each in
source/overlays/OVL/recomp/, included where the stub's pragma is. Registers and the PS1 stack frame are kept, so even
uninitialized reads see the frame's own bytes. Addresses become symbols from obj/asm_OVL_lhs.map, through asm names, so
the C names don't clash with the file's declarations. shortcut: struct-by-value arguments aren't handled; a link or
crash there needs that call by hand."""
import bisect, os, re, struct, sys
ovl = sys.argv[1]
ad, out = 'asm/overlays/' + ovl, 'source/overlays/%s/recomp' % ovl
os.makedirs(out, exist_ok=True)
names = {}
for l in open('obj/asm_%s_lhs.map' % ovl, errors='ignore'):
    p = l.split()
    if len(p) == 2 and re.match(r'^[0-9A-F]{8}$', p[0]):
        names.setdefault(int(p[0], 16), p[1])
keys = sorted(names)
bin_ = open('build/%s.matching.bin' % ovl, 'rb').read()
BASE = int(sys.argv[2], 16)  # the overlay's load address
def word(a): return struct.unpack_from('<I', bin_, a - BASE)[0]
def s16(x): return x - 65536 if x & 0x8000 else x
def isaddr(h): return 0x8000 <= h < 0x8020

def sym(addr, used):
    i = bisect.bisect_right(keys, addr) - 1
    n = names[keys[i]]; off = addr - keys[i]
    used.add(n)
    return '((int)R_%s + %d)' % (n, off) if off else '(int)R_%s' % n

def translate(path):
    t = open(path, errors='ignore').read()
    m = re.search(r'dw 0x[0-9A-Fa-f]{8} ; ([0-9A-Fa-f]{8})', t)
    start = int(m.group(1), 16)
    ws = [int(x, 16) for x in re.findall(r'dw 0x([0-9A-Fa-f]{8})', t)]
    # the split can cut a function: a branch past the end pulls in the following stubs
    files = sorted((g for g in os.listdir(ad) if g.endswith('.s')), key=lambda g: g.split('_')[-1])
    while True:
        last = start + 4 * len(ws)
        far = [start + i * 4 + 4 + s16(w & 0xffff) * 4 for i, w in enumerate(ws) if w >> 26 in (4, 5, 6, 7) or w >> 26 == 1]
        far += [((start + i * 4 + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2) for i, w in enumerate(ws) if w >> 26 == 2]
        if not any(last <= x < last + 0x2000 for x in far): break
        nxt = [g for g in files if int(g[:-2].split('_')[-1], 16) == last]
        if not nxt: break
        ws += [int(x, 16) for x in re.findall(r'dw 0x([0-9A-Fa-f]{8})', open(os.path.join(ad, nxt[0]), errors='ignore').read())]
    name = re.search(r'xdef (\S+)', t).group(1)
    used, funcs, labels, hi = set(), set(), set(), {}
    end = start + 4 * len(ws)
    frame = 0
    for i, w in enumerate(ws):
        pc = start + i * 4; o = w >> 26
        if o in (1, 4, 5, 6, 7): labels.add(pc + 4 + s16(w & 0xffff) * 4)
        if o == 2: labels.add(((pc + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2))
        if w >> 16 == 0x27BD and w & 0x8000 and not frame: frame = 65536 - (w & 0xffff)
    tables = {}
    def ins(i, tail=None):
        pc = start + i * 4; w = ws[i]; o = w >> 26
        rs, rt, rd, sa, fn = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31, w & 63
        imm = w & 0xffff; si = s16(imm)
        R = lambda n: '0' if n == 0 else 'r[%d]' % n
        def wr(n, e): return '' if n == 0 else 'r[%d] = %s;' % (n, e)
        lo = si
        ea = None
        # the lui can be in a branch's delay slot, before the branch's target in another path
        if o == 9 and rs == rt and rs not in hi and abs(si) >= 0x1000:
            for k, x in enumerate(ws):
                if x >> 16 == 0x3C00 | rt and isaddr(x & 0xffff):
                    hi[rs] = x & 0xffff
        if o in (8, 9) or o >= 32 or o == 13:
            if rs in hi:
                a = (hi[rs] << 16) + (si if o != 13 else imm)
                ea = sym(a & 0xffffffff, used)
        if o == 15:
            if isaddr(imm): hi[rt] = imm; return wr(rt, '0;')[:-1]
            hi.pop(rt, None); return wr(rt, '0x%x' % (imm << 16))
        if o == 0:
            d = rd
            if fn == 33 or fn == 32:
                if rs in hi or rt in hi:
                    h = hi.get(rs, hi.get(rt))
                    if d: hi[d] = h
                elif d in hi: hi.pop(d)
                return wr(d, '(u)%s + (u)%s' % (R(rs), R(rt)))
            hi.pop(d, None)
            if fn == 0: return '' if w == 0 else wr(d, '(u)%s << %d' % (R(rt), sa))
            if fn == 2: return wr(d, '(u)%s >> %d' % (R(rt), sa))
            if fn == 3: return wr(d, '(int)%s >> %d' % (R(rt), sa))
            if fn == 4: return wr(d, '(u)%s << (%s & 31)' % (R(rt), R(rs)))
            if fn == 6: return wr(d, '(u)%s >> (%s & 31)' % (R(rt), R(rs)))
            if fn == 7: return wr(d, '(int)%s >> (%s & 31)' % (R(rt), R(rs)))
            if fn in (34, 35): return wr(d, '(u)%s - (u)%s' % (R(rs), R(rt)))
            if fn == 36: return wr(d, '%s & %s' % (R(rs), R(rt)))
            if fn == 37: return wr(d, '%s | %s' % (R(rs), R(rt)))
            if fn == 38: return wr(d, '%s ^ %s' % (R(rs), R(rt)))
            if fn == 39: return wr(d, '~(%s | %s)' % (R(rs), R(rt)))
            if fn == 42: return wr(d, '(int)%s < (int)%s' % (R(rs), R(rt)))
            if fn == 43: return wr(d, '(u)%s < (u)%s' % (R(rs), R(rt)))
            if fn == 24: return 'mul = (long long)(int)%s * (int)%s; hi_ = mul >> 32; lo_ = mul;' % (R(rs), R(rt))
            if fn == 25: return 'mul = (unsigned long long)(u)%s * (u)%s; hi_ = mul >> 32; lo_ = mul;' % (R(rs), R(rt))
            if fn == 26: return 'if (%s) { lo_ = (int)%s / (int)%s; hi_ = (int)%s %% (int)%s; }' % (R(rt), R(rs), R(rt), R(rs), R(rt))
            if fn == 27: return 'if (%s) { lo_ = (u)%s / (u)%s; hi_ = (u)%s %% (u)%s; }' % (R(rt), R(rs), R(rt), R(rs), R(rt))
            if fn == 16: return wr(d, 'hi_')
            if fn == 18: return wr(d, 'lo_')
            if fn == 13: return ''
            raise SystemExit('%s: op %08x at %x' % (name, w, pc))
        if o >= 32:
            base = ea if ea else '(u)%s + %d' % (R(rs), si)
            if ea and rs: base = '(u)%s + %s' % (R(rs), ea)
            A = '(%s)' % base
            if o not in (40, 41, 43, 42, 46): hi.pop(rt, None)
            return {32: wr(rt, '*(signed char *)%s' % A), 33: wr(rt, '*(short *)%s' % A), 35: wr(rt, '*(int *)%s' % A),
                    36: wr(rt, '*(unsigned char *)%s' % A), 37: wr(rt, '*(unsigned short *)%s' % A),
                    40: '*(char *)%s = %s;' % (A, R(rt)), 41: '*(short *)%s = %s;' % (A, R(rt)),
                    43: '*(int *)%s = %s;' % (A, R(rt)),
                    34: 'r[%d] = LWL(%s, r[%d]);' % (rt, A, rt), 38: 'r[%d] = LWR(%s, r[%d]);' % (rt, A, rt),
                    42: 'SWL(%s, %s);' % (A, R(rt)), 46: 'SWR(%s, %s);' % (A, R(rt))}[o]
        if o in (8, 9):
            if ea:
                if rt: hi.pop(rt, None)
                return wr(rt, '(u)%s + %s' % (R(rs), ea))
            if rs in hi and rt: pass
            hi.pop(rt, None)
            return wr(rt, '(u)%s + %d' % (R(rs), si))
        hi.pop(rt, None)
        if o == 10: return wr(rt, '(int)%s < %d' % (R(rs), si))
        if o == 11: return wr(rt, '(u)%s < (u)%d' % (R(rs), si))
        if o == 12: return wr(rt, '%s & %d' % (R(rs), imm))
        if o == 13: return wr(rt, ea if ea else '%s | %d' % (R(rs), imm))
        if o == 14: return wr(rt, '%s ^ %d' % (R(rs), imm))
        raise SystemExit('%s: op %08x at %x' % (name, w, pc))
    lines, i = [], 0
    n = len(ws)
    while i < n:
        pc = start + i * 4; w = ws[i]; o = w >> 26
        if pc in labels: lines.append('L%x:;' % pc)
        rs, rt, fn = (w >> 21) & 31, (w >> 16) & 31, w & 63
        R = lambda x: '0' if x == 0 else 'r[%d]' % x
        ctrl = None
        tgt = pc + 4 + s16(w & 0xffff) * 4
        if o == 2:
            ctrl = 'goto L%x;' % (((pc + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2))
        elif o == 3:
            t = ((pc + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2)
            funcs.add(names[t])
            ctrl = 'CALL(R_%s);' % names[t]
        elif o == 0 and fn == 8:
            if rs == 31:
                ctrl = 'goto out;'
            else:
                # a jump table: the labels in the PS1's rodata, read at the jr
                tb = None
                for j in range(i - 1, max(i - 6, -1), -1):
                    if ws[j] >> 26 == 15 and isaddr(ws[j] & 0xffff):
                        h = ws[j] & 0xffff
                        for k in range(j, i):
                            if ws[k] >> 26 == 35: tb = (h << 16) + s16(ws[k] & 0xffff)
                L = []
                a = tb
                while tb and start <= word(a) < end: L.append(word(a)); a += 4
                labels.update(L)
                ctrl = 'switch ((u)r[%d]) { %s default: goto out; }' % (rs, ' '.join('case 0x%x: goto L%x;' % (x, x) for x in sorted(set(L))))
                tables[pc] = L
        elif o == 0 and fn == 9:
            ctrl = 'CALL((int (*)())r[%d]);' % rs
        elif o == 4: ctrl = 'if (%s == %s) goto L%x;' % (R(rs), R(rt), tgt)
        elif o == 5: ctrl = 'if (%s != %s) goto L%x;' % (R(rs), R(rt), tgt)
        elif o == 6: ctrl = 'if ((int)%s <= 0) goto L%x;' % (R(rs), tgt)
        elif o == 7: ctrl = 'if ((int)%s > 0) goto L%x;' % (R(rs), tgt)
        elif o == 1 and rt == 0: ctrl = 'if ((int)%s < 0) goto L%x;' % (R(rs), tgt)
        elif o == 1 and rt == 1: ctrl = 'if ((int)%s >= 0) goto L%x;' % (R(rs), tgt)
        if ctrl:
            if ctrl.startswith('if'):
                # the condition is taken before the delay slot
                c = ctrl[3:ctrl.index(') goto')+1]; g = ctrl[ctrl.index('goto'):]
                lines.append('c = (%s); %s if (c) %s' % (c, ins(i + 1), g))
            elif ctrl.startswith('switch') or ctrl.startswith('CALL((int'):
                lines.append('t = r[%d]; %s %s' % (rs, ins(i + 1), ctrl.replace('(u)r[%d]' % rs, '(u)t').replace('())r[%d]' % rs, '())t')))
            else:
                lines.append('%s %s' % (ins(i + 1), ctrl))
            i += 2
            continue
        lines.append(ins(i)); i += 1
    labelset = {int(x, 16) for x in re.findall(r'^L([0-9a-f]+):', '\n'.join(lines), re.M)}
    for x in sorted(set(re.findall(r'goto L([0-9a-f]+)', '\n'.join(lines)))):
        if int(x, 16) not in labelset:
            print('%s: branch out to %s, a return here' % (name, x)); lines.append('L%s: goto out;' % x)
    dec = ''
    for s in sorted(used): dec += 'extern char R_%s[] __asm__("%s");\n' % (s, s)
    for s in sorted(funcs - used): dec += 'extern char R_%s[] __asm__("%s");\n' % (s, s)
    # no duplicates between data and call use
    both = funcs & used
    body = '\n'.join('    ' + l for l in lines if l)
    return '''%sint G_%s(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("%s");
int G_%s(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(%d)
%s
out:
    return r[2];
}
''' % (dec, name, name, name, frame, body)

made = []
for f in sorted(os.listdir(ad)):
    if not f.endswith('.s'): continue
    t = open(os.path.join(ad, f), errors='ignore').read()
    if 'dw 0x' not in t or 'xdef' not in t: continue
    open(os.path.join(out, f[:-2] + '.inc'), 'w').write(translate(os.path.join(ad, f)))
    made.append(f)
print(len(made), 'functions')
for root, _, fs in os.walk('source/overlays/' + ovl):
    for f in fs:
        if not f.endswith('.c'): continue
        p = os.path.join(root, f); s = open(p, errors='surrogateescape', encoding='utf-8').read()
        n = re.sub(r'^#pragma INCLUDE_ASM\("asm/overlays/%s/(\S+)\.s"\)$' % ovl,
                   lambda m: '#ifdef MGS_PORT\n#include "overlays/%s/recomp/%s.inc"\n#else\n%s\n#endif' % (ovl, m.group(1), m.group(0)), s, flags=re.M)
        if n != s:
            if '#include "recomp.h"' not in n:
                n = '#ifdef MGS_PORT\n#include "recomp.h"\n#endif\n' + n
            open(p, 'w', errors='surrogateescape', encoding='utf-8').write(n)
