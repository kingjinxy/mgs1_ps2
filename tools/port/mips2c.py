#!/usr/bin/env python3
"""mips2c.py OVL: each INCLUDE_ASM stub of an overlay as exact-behaviour C for the port (MGS_PORT), one file each in
source/overlays/OVL/recomp/, included where the stub's pragma is. Registers and the PS1 stack frame are kept, so even
uninitialized reads see the frame's own bytes. Addresses become symbols from obj/asm_OVL_lhs.map, through asm names, so
the C names don't clash with the file's declarations. Calls of C functions that take a struct by value
(the PS1 passes it in two registers, the EE in one) go to a PS1-ABI wrapper (the rename table at the call: NewShadow*);
C calling translated code that way needs one too (stage_split.py's ABI_WRAP). docs/Stage Overlay Translation.md."""
import bisect, os, re, struct, sys
ovl = sys.argv[1]
ad, out = 'asm/overlays/' + ovl, 'source/overlays/%s/recomp' % ovl
if not os.path.isdir(ad):
    ad = 'obj_ps2/stage_split/' + ovl  # an overlay the decomp hasn't split (tools/port/stage_split.py)
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
    if off >= 4 and 'word' in n:
        # likely a static of another object (not in the map), whose place differs in the port: make it STATIC
        # (mgstype.h, global without the keyword) so the map names it (s07b's chair_alive was dword_800C3404+124)
        print('warning: %08X read as %s+%d: a static past that symbol?' % (addr, n, off))
    return '((int)R_%s + %d)' % (n, off) if off else '(int)R_%s' % n

def targets(start, ws):
    for i, w in enumerate(ws):
        if w >> 26 in (1, 4, 5, 6, 7): yield i, start + i * 4 + 4 + s16(w & 0xffff) * 4
        if w >> 26 == 2: yield i, ((start + i * 4 + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2)

def cuts(start, ws):
    """Where a new function starts in a stub: after a jr ra that no earlier branch jumps past."""
    out = []
    for i in range(len(ws) - 2):
        p = start + (i + 2) * 4
        if ws[i] == 0x03E00008 and (ws[i + 2] >> 16 == 0x27BD or p in taken):
            if not any(n < i and t >= p for n, t in targets(start, ws)):
                out.append(i + 2)
    return out

def translate(path, seg=None):
    t = open(path, errors='ignore').read()
    m = re.search(r'dw 0x[0-9A-Fa-f]{8} ; ([0-9A-Fa-f]{8})', t)
    start = int(m.group(1), 16)
    ws = [int(x, 16) for x in re.findall(r'dw 0x([0-9A-Fa-f]{8})', t)]
    if seg:
        ws, start = ws[seg[0]:seg[1]], start + seg[0] * 4  # the last piece can run on into the next file
    # the split can cut a function: a branch past the end pulls in the following stubs
    files = sorted((g for g in os.listdir(ad) if g.endswith('.s')), key=lambda g: g.split('_')[-1])
    while True:
        last = start + 4 * len(ws)
        far = [start + i * 4 + 4 + s16(w & 0xffff) * 4 for i, w in enumerate(ws) if w >> 26 in (4, 5, 6, 7) or w >> 26 == 1]
        far += [((start + i * 4 + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2) for i, w in enumerate(ws) if w >> 26 == 2]
        if (seg and not seg[2]) or not any(last <= x < last + 0x2000 for x in far): break
        nxt = [g for g in files if int(g[:-2].split('_')[-1], 16) == last]
        if not nxt: break
        ws += [int(x, 16) for x in re.findall(r'dw 0x([0-9A-Fa-f]{8})', open(os.path.join(ad, nxt[0]), errors='ignore').read())]
    name = re.search(r'xdef (\S+)', t).group(1)
    if seg and seg[0]: name = names[start]
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
            if rs not in hi and (rs, si) in seen and o >= 32:
                hi[rs] = seen[rs, si]  # the same address on another path
            if rs in hi:
                seen[rs, si] = hi[rs]
                a = (hi[rs] << 16) + (si if o != 13 else imm)
                ea = sym(a & 0xffffffff, used)
        if o == 18:  # the GTE, through the HAL's software one (port/gte.h)
            if w >> 25 & 1: return 'Gte_Command(0x%x);' % (w & 0x1FFFFFF)
            if rs == 0: hi.pop(rt, None); return wr(rt, 'Gte_DataRead(%d)' % rd)
            if rs == 2: hi.pop(rt, None); return wr(rt, 'Gte_CtrlRead(%d)' % rd)
            if rs == 4: return 'Gte_DataWrite(%d, %s);' % (rd, R(rt))
            if rs == 6: return 'Gte_CtrlWrite(%d, %s);' % (rd, R(rt))
            raise SystemExit('%s: cop2 %08x at %x' % (name, w, pc))
        if o in (50, 58):  # lwc2, swc2
            base = ea if ea else '(u)%s + %d' % (R(rs), si)
            if ea and rs: base = '(u)%s + %s' % (R(rs), ea)
            if o == 50: return 'Gte_DataWrite(%d, *(int *)(%s));' % (rt, base)
            return '*(int *)(%s) = Gte_DataRead(%d);' % (base, rt)
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
    pending = {}
    seen = {}
    n = len(ws)
    while i < n:
        pc = start + i * 4; w = ws[i]; o = w >> 26
        if pc in labels:
            lines.append('L%x:;' % pc)
            hi.update(pending.get(pc, {}))  # a lui in the delay slot of a branch here
        rs, rt, fn = (w >> 21) & 31, (w >> 16) & 31, w & 63
        R = lambda x: '0' if x == 0 else 'r[%d]' % x
        ctrl = None
        tgt = pc + 4 + s16(w & 0xffff) * 4
        if o == 2:
            ctrl = 'goto L%x;' % (((pc + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2))
        elif o == 3:
            t = ((pc + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2)
            # game logic's tick (tas_replay.c); and C functions taking a struct by value, which the PS1 passes in two
            # registers and the EE in one (shadow.c's Port_NewShadow*: the PS1's argument registers)
            n_ = {'mts_get_tick_count': 'Port_GameTick', 'NewShadow': 'Port_NewShadow',
                  'NewShadow2': 'Port_NewShadow2'}.get(names[t], names[t])
            funcs.add(n_)
            ctrl = 'CALL(R_%s);' % n_
        elif o == 0 and fn == 8:
            if rs == 31:
                ctrl = 'goto out;'
            else:
                # a jump table: the labels in the PS1's rodata, read at the jr
                tb = None
                for j in range(i - 1, max(i - 12, -1), -1):
                    if ws[j] >> 26 == 15 and isaddr(ws[j] & 0xffff):
                        h, hr = ws[j] & 0xffff, (ws[j] >> 16) & 31
                        for k in range(j + 1, i):
                            if ws[k] >> 26 in (9, 35) and (ws[k] >> 21) & 31 == hr:
                                tb = (h << 16) + s16(ws[k] & 0xffff); break
                        break
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
            d = ws[i + 1]
            if d >> 26 == 15 and isaddr(d & 0xffff) and (o in (1, 2, 4, 5, 6, 7)):
                to = ((pc + 4) & 0xF0000000) | ((w & 0x3ffffff) << 2) if o == 2 else tgt
                pending.setdefault(to, {})[(d >> 16) & 31] = d & 0xffff
            if ctrl.startswith('if'):
                # the condition is taken before the delay slot
                c = ctrl[3:ctrl.index(') goto')+1]; g = ctrl[ctrl.index('goto'):]
                lines.append('c = (%s); %s if (c) %s' % (c, ins(i + 1), g))
            elif ctrl.startswith('switch') or ctrl.startswith('CALL((int'):
                lines.append('t = r[%d]; %s %s' % (rs, ins(i + 1), ctrl.replace('(u)r[%d]' % rs, '(u)t').replace('())r[%d]' % rs, '())t')))
            else:
                lines.append('%s %s' % (ins(i + 1), ctrl))
            if o == 3 or (o == 0 and fn == 9):
                # a call clobbers the caller-saved registers: a lui before it doesn't pair with an addiu after
                # (s07b 800C8CCC: v0 = GV_VecDir2() + 0x800 was taken for an address 0x800B0800)
                for x in list(range(1, 16)) + [24, 25, 31]:
                    hi.pop(x, None)
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
    return '''%sint G_%s(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("%s");
int G_%s(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(%d)
%s
out:
    RECOMP_RETURN;
}
''' % (dec, name, name, name, frame, body)

made = []
parts = {}
taken = set()  # code addresses the stubs take (callbacks): each one an entry point
for f in os.listdir(ad):
    for x in re.findall(r'dw 0x([0-9A-Fa-f]{8})', open(os.path.join(ad, f), errors='ignore').read()) if f.endswith('.s') else []:
        pass
for f in os.listdir(ad):
    if not f.endswith('.s'): continue
    w = [int(x, 16) for x in re.findall(r'dw 0x([0-9A-Fa-f]{8})', open(os.path.join(ad, f), errors='ignore').read())]
    h = {}
    for x in w:
        if x >> 26 == 15: h[(x >> 16) & 31] = x & 0xffff
        elif x >> 26 == 9 and ((x >> 21) & 31) in h: taken.add(((h[(x >> 21) & 31] << 16) + s16(x & 0xffff)) & 0xffffffff)
for f in sorted(os.listdir(ad)):
    if not f.endswith('.s'): continue
    t = open(os.path.join(ad, f), errors='ignore').read()
    m = re.search(r'dw 0x[0-9A-Fa-f]{8} ; ([0-9A-Fa-f]{8})', t)
    if not m or 'xdef' not in t: continue
    st = int(m.group(1), 16); ws = [int(x, 16) for x in re.findall(r'dw 0x([0-9A-Fa-f]{8})', t)]
    c = cuts(st, ws); parts[f] = [0] + c + [len(ws)]
    for k in c:
        a = st + k * 4
        if a not in names: names[a] = '%s_rc_%X' % (ovl, a)
keys[:] = sorted(names)
print(sum(len(v) - 2 for v in parts.values()), 'extra entry points')
for f in sorted(os.listdir(ad)):
    if not f.endswith('.s'): continue
    t = open(os.path.join(ad, f), errors='ignore').read()
    if 'dw 0x' not in t or 'xdef' not in t: continue
    pp = parts[f]
    txt = translate(os.path.join(ad, f)) if len(pp) == 2 else ''.join(translate(os.path.join(ad, f), (pp[k], pp[k + 1], k == len(pp) - 2)) for k in range(len(pp) - 1))
    open(os.path.join(out, f[:-2] + '.inc'), 'w').write(txt)
    made.append(f)
print(len(made), 'functions')
for root, _, fs in os.walk('source/overlays/' + ovl):
    for f in fs:
        if not f.endswith('.c'): continue
        p = os.path.join(root, f); s = open(p, errors='surrogateescape', encoding='utf-8').read()
        n = re.sub(r'(?<!#else\n)^#pragma INCLUDE_ASM\("asm/overlays/%s/(\S+)\.s"\)$' % ovl,
                   lambda m: '#ifdef MGS_PORT\n#include "overlays/%s/recomp/%s.inc"\n#else\n%s\n#endif' % (ovl, m.group(1), m.group(0)), s, flags=re.M)
        if n != s:
            if '#include "recomp.h"' not in n:
                n = '#ifdef MGS_PORT\n#include "recomp.h"\n#endif\n' + n
            open(p, 'w', errors='surrogateescape', encoding='utf-8').write(n)
