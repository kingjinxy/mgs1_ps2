#!/usr/bin/env python3
"""stage_split.py OVL: a stage overlay the decomp hasn't split (s10a, ...), from the disc's STAGE.DIR, into what
mips2c.py and build/overlays_ps2.py take, for the port only (Running Walkthrough Step 32):

  build/OVL.matching.bin             the stage binary as on the disc (mips2c.py reads jump tables from it)
  obj_ps2/stage_split/OVL/OVL_<ADDR>.s  one stub per function (dw words, as the decomp's; outside asm/ and with no
                                     INCLUDE_ASM, which the matching build would pick up: mips2c.py looks here)
  obj/asm_OVL_lhs.map                the resident symbols, and generated names for the overlay's own addresses
  obj/linker_command_file_OVL_lhs.txt  the stage table and the overlay's C
  source/overlays/OVL/OVL.c          all under MGS_PORT (the matching build compiles every source): mips2c.py's
                                     C for each function, and the overlay's data:
                                     .data, .rodata and .bss as blocks in the PS1's layout, so an address written as
                                     "label + offset" is always right; words pointing at overlay data, overlay
                                     functions or resident code/data are symbols, the rest the PS1's values (jump
                                     tables stay PS1 addresses: mips2c.py switches on them)
  source/overlays/OVL/stage_table.inc  the stage table by symbol (source/stage/OVL.c includes it under MGS_PORT)

Then: python3 tools/port/mips2c.py OVL 0x800C3208. shortcut: a data word that only looks like a pointer (a number
in 0x80010000..the overlay's end) is relocated all the same; the TAS replay is the check."""
import bisect, os, re, struct, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
DISCS = [os.path.expanduser('~/emu/mgs-integral/disc%d.bin' % n) for n in (1, 2)]  # a disc 2 stage: s15a, ...
BASE, RES = 0x800C3208, 0x80010000
ovl = sys.argv[1]
os.chdir(ROOT)


def disc_stage(name, disc):
    f = open(disc, 'rb')
    def sec(n, c=1):
        b = b''
        for i in range(c):
            f.seek((n + i) * 2352 + 24); b += f.read(2048)
        return b
    def find(lba, size, want):
        d, i = sec(lba, (size + 2047) // 2048), 0
        while i < len(d):
            if d[i] == 0:
                i = (i // 2048 + 1) * 2048; continue
            if d[i + 33:i + 33 + d[i + 32]].decode('latin1').split(';')[0] == want:
                return struct.unpack_from('<I', d, i + 2)[0], struct.unpack_from('<I', d, i + 10)[0]
            i += d[i]
        raise SystemExit('%s not on the disc' % want)
    root = sec(16)[156:190]
    mgs = find(struct.unpack_from('<I', root, 2)[0], struct.unpack_from('<I', root, 10)[0], 'MGS')
    lba, _ = find(mgs[0], mgs[1], 'STAGE.DIR')
    hdr = sec(lba)
    for i in range(struct.unpack_from('<I', hdr, 0)[0] // 12):
        n, off = hdr[4 + 12 * i:12 + 12 * i].rstrip(b'\0').decode(), struct.unpack_from('<i', hdr, 12 + 12 * i)[0]
        if n != name:
            continue
        h, i, s = sec(lba + off, 2), 4, lba + off + 1
        while True:
            _, _, ext, size = struct.unpack_from('<HccI', h, i); i += 8
            if size == 0:
                break
            if ext == b'b':
                return sec(s, (size + 2047) // 2048)[:size]
            s += (size + 2047) // 2048
    return None  # not on this disc


def s16(x): return x - 65536 if x & 0x8000 else x


b = next((x for x in (disc_stage(ovl, d) for d in DISCS) if x), None)
if b is None:
    raise SystemExit('stage %s: no .bin on either disc' % ovl)
open('build/%s.matching.bin' % ovl, 'wb').write(b)
W = list(struct.unpack('<%dI' % (len(b) // 4), b[:len(b) // 4 * 4]))
END = BASE + len(b)
at = lambda a: W[(a - BASE) // 4]

# resident symbols: the main executable's part of any built overlay's map (the same in all)
res = {}
for l in open('obj/asm_s07b_lhs.map', errors='ignore'):
    p = l.split()
    if len(p) == 2 and re.match(r'^[0-9A-F]{8}$', p[0]) and int(p[0], 16) < BASE:
        res.setdefault(int(p[0], 16), p[1])
rkeys = sorted(res)

# the stage table's constructors (source/stage/OVL.c), the code's first roots
table = open('source/stage/%s.c' % ovl, encoding='utf-8').read()
ctors = [int(x, 16) for x in re.findall(r'\(NEWCHARA \*\)0x([0-9a-f]{8})', table)]
seeds = {a for a in ctors if BASE <= a < END}

# code: from the first function the table or a call reaches, to the last jr ra of the binary
def is_prologue(a): return BASE <= a < END and at(a) >> 16 == 0x27BD and at(a) & 0x8000
calls = {(((BASE + 4 * i) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)) for i, w in enumerate(W) if w >> 26 == 3}
calls = {a for a in calls if BASE <= a < END}
tstart = min(a for a in seeds | {a for a in calls if is_prologue(a)})
tend = max(BASE + 4 * i for i, w in enumerate(W) if w == 0x03E00008) + 8
def built(lo, hi_):  # addresses the code in [lo, hi_) builds with lui + addiu/ori/load/store
    out, h = set(), {}
    for i in range((lo - BASE) // 4, (hi_ - BASE) // 4):
        w = W[i]; o = w >> 26; rs, rt = (w >> 21) & 31, (w >> 16) & 31
        if o == 15:
            h[rt] = w & 0xFFFF; continue
        if (o in (9, 13) or o >= 32) and rs in h:
            out.add(((h[rs] << 16) + (w & 0xFFFF if o == 13 else s16(w & 0xFFFF))) & 0xFFFFFFFF)
        if o in (2, 3) or w == 0x03E00008:
            h.clear()
    return out
# the rodata begins at the first address past the last frame setup that the code refers to (a word there can
# look like a jr ra: s08b)
# (a frame setup that something calls or names: s19a's file ends in stale code, after its bss's zeros)
last = max(a for a in seeds | calls | built(tstart, tend) if not a & 3 and is_prologue(a))
after = [a for a in built(tstart, tend) if last < a < tend]
if after:
    tend = min(tend, (min(after) // 4) * 4)
    # back to the last return: the first strings may have no reference (s19a's "countdwn.c")
    tend = max(a for a in range(tstart, tend, 4) if at(a) == 0x03E00008) + 8
while True:  # functions before the first called one with a frame: reached only by address (s18a: an actor's act
    # and die), or a called leaf with no frame (s19a's 800C3958)
    low = [a for a in built(tstart, tend) if BASE <= a < tstart and not a & 3 and is_prologue(a)]
    low += [a for a in calls if a < tstart and any(W[i] >> 26 == 3 and W[i] & 0x3FFFFFF == (a >> 2) & 0x3FFFFFF
                                                   for i in range((tstart - BASE) // 4, (tend - BASE) // 4))]
    if not low: break
    tstart = min(low)
code = range((tstart - BASE) // 4, (tend - BASE) // 4)
# from here, only the code's own calls (s19a: jal-like words in the stale code cut two functions in the middle)
calls = {a for a in ((((BASE + 4 * i) & 0xF0000000) | ((W[i] & 0x3FFFFFF) << 2)) for i in code if W[i] >> 26 == 3)
         if BASE <= a < END}

# jump tables: a table address built (lui + addiu, as mips2c.py reads it) shortly before a jr through a register;
# its entries stay PS1 addresses (mips2c.py switches on them), every other data word into code is a function
jtab = set()
for i in code:
    w = W[i]
    if w & 0xFC1FFFFF == 0x00000008 and (w >> 21) & 31 != 31:  # jr reg
        for j in range(i - 1, max(i - 12, tstart // 4 - BASE // 4 - 1), -1):
            if W[j] >> 26 == 15 and 0x8000 <= W[j] & 0xFFFF < 0x8020:
                h, hr = W[j] & 0xFFFF, (W[j] >> 16) & 31
                for k in range(j + 1, i):
                    if W[k] >> 26 in (9, 35) and (W[k] >> 21) & 31 == hr:
                        a = ((h << 16) + s16(W[k] & 0xFFFF)) & 0xFFFFFFFF
                        while BASE <= a < END and tstart <= at(a) < tend:
                            jtab.add(a); a += 4
                        break
                break

# addresses the code builds (lui + addiu/ori/load/store), and the bss beyond the binary
refs, hi = set(), {}
for i in code:
    w = W[i]; o = w >> 26; rs, rt = (w >> 21) & 31, (w >> 16) & 31
    if w >> 26 == 15:
        hi[rt] = w & 0xFFFF; continue
    if (o in (9, 13) or o >= 32) and rs in hi:
        refs.add(((hi[rs] << 16) + (w & 0xFFFF if o == 13 else s16(w & 0xFFFF))) & 0xFFFFFFFF)
    if o in (2, 3) or w == 0x03E00008:
        hi.clear()
bss_end = max([END] + [a + 4 for a in refs if END <= a < END + 0x20000])
bss_end = (bss_end + 15) & ~15

funcs = set(seeds) | calls | {a for a in refs if tstart <= a < tend and (is_prologue(a) or a in calls)}
for i in code:  # after a jr ra and its delay slot, a frame setup starts the next function
    if W[i] == 0x03E00008 and BASE + 4 * (i + 2) < tend and is_prologue(BASE + 4 * (i + 2)):
        funcs.add(BASE + 4 * (i + 2))
for a in list(range(BASE, tstart, 4)) + list(range(tend, END - 3, 4)):  # function pointers in data
    v = at(a)
    if a not in jtab and tstart <= v < tend and not v & 3 and \
            (is_prologue(v) or at(v - 8) == 0x03E00008 or (at(v - 4) == 0 and at(v - 12) == 0x03E00008)):
        funcs.add(v)  # else mid-function: a jump table the search above missed, PS1 values
funcs = sorted(a for a in funcs if tstart <= a < tend)
fname = lambda a: '%s_%08X' % (ovl, a)
if os.environ.get('CHECK'):  # a split overlay: the code range and starts against its real map, nothing written
    real = {}
    for l in open('obj/asm_%s_lhs.map' % ovl, errors='ignore'):
        p = l.split()
        if len(p) == 2 and re.match(r'^[0-9A-F]{8}$', p[0]) and tstart - 64 <= int(p[0], 16) < tend: real[int(p[0], 16)] = p[1]
    m = open('obj/asm_%s_lhs.map' % ovl, errors='ignore').read()
    t = re.search(r'([0-9A-F]{8}) ([0-9A-F]{8}) [0-9A-F]{8} [0-9A-F]{8} overlay\s+overlay\.text', m)
    fs = set(funcs)
    print('code %08X-%08X, map .text %s-%s; %d starts, %d map symbols in code, %d of them found, %d extra'
          % (tstart, tend, t.group(1), t.group(2), len(fs), len(real), len(fs & set(real)), len(fs - set(real))))
    tp = [(a, at(a)) for a in range(BASE, tstart, 4)] + [(a, at(a)) for a in range(tend, END - 3, 4)]
    tp = [(a, v) for a, v in tp if tstart <= v < tend]
    print('jump table words %d: at map functions %d; other data words into code %d: at map functions %d'
          % (len(jtab), sum(at(a) in real for a in jtab), len([a for a, _ in tp if a not in jtab]), sum(v in real for a, v in tp if a not in jtab)))
    for a, v in tp:
        if a not in jtab and v not in real: print('  other: %08X -> %08X' % (a, v))
    after_ret = lambda v: at(v - 8) == 0x03E00008 or (at(v - 4) == 0 and at(v - 12) == 0x03E00008)
    cand = {v for _, v in tp if after_ret(v)}
    print('after-a-return rule: %d targets, %d real functions, %d not; real ones still missed: %d'
          % (len(cand), len(cand & set(real)), len(cand - set(real)), len({v for _, v in tp if v in real} - fs - cand)))
    print('data words into code: %d; at map functions %d (%d of those among the starts found), elsewhere %d'
          % (len(tp), sum(v in real for _, v in tp), sum(v in real and v in fs for _, v in tp), sum(v not in real for _, v in tp)))
    sys.exit(0)

# data words that point somewhere: relocated, with a label at each overlay address pointed at
regions = [('data', BASE, tstart), ('rodata', tend, END)]
labels = {a for a in refs if BASE <= a < tstart or tend <= a < bss_end}
ptrs = {}
for _, lo, hi_ in regions:
    for a in range(lo, hi_ - 3, 4):
        if (a - BASE) & 3:
            continue
        v = at(a)
        if v in funcs:
            ptrs[a] = fname(v)
        elif BASE <= v < tstart or tend <= v < bss_end:
            ptrs[a] = v; labels.add(v)
        elif RES <= v < BASE:
            k = rkeys[bisect.bisect_right(rkeys, v) - 1]
            ptrs[a] = res[k] + ('+%d' % (v - k) if v != k else '')
labels.update({lo for _, lo, _ in regions}); labels.add(END)
labels = sorted(a for a in labels if BASE <= a < tstart or tend <= a <= bss_end)
lname = lambda a: '%s_dat_%08X' % (ovl, a)

# stubs
ad = 'obj_ps2/stage_split/%s' % ovl
os.makedirs(ad, exist_ok=True)
for g in os.listdir(ad):
    if g.endswith('.s'): os.remove(os.path.join(ad, g))
for a, n in zip(funcs, funcs[1:] + [tend]):
    body = ''.join('\tdw 0x%08X ; %08X\n' % (at(x), x) for x in range(a, n, 4))
    open(os.path.join(ad, fname(a) + '.s'), 'w').write(
        '\topt\tc+, at+, e+, n-\n\tsection .text\n\n\txdef %s\n%s:\n%s' % (fname(a), fname(a), body))

# map: resident symbols, the functions, the data labels
with open('obj/asm_%s_lhs.map' % ovl, 'w') as f:
    f.write('  Address  Names alphabetically (generated by tools/port/stage_split.py)\n')
    for a in rkeys: f.write(' %08X  %s\n' % (a, res[a]))
    for a in funcs: f.write(' %08X  %s\n' % (a, fname(a)))
    for a in labels: f.write(' %08X  %s\n' % (a, lname(a)))

# functions C calls with a struct by value (the PS1 passes it in two registers, the EE in one): the data points at a
# C wrapper that calls the translated code with the PS1's registers (port/src/hal_game.c)
# DEMOID_SHADOW (0x000f), the stage's copy of NewDemoKage: demoexec.c passes an SVECTOR. The wrapper is written into
# OVL.c: the link makes an overlay's functions local (one in hal_game.c reached a link stub instead, s10a's)
kage = re.search(r'\{ 0x000f, \(NEWCHARA \*\)0x([0-9a-f]{8}) \}', table)
ABI_WRAP = {fname(int(kage.group(1), 16)): 'Port_%s_DemoKage' % ovl} if kage and BASE <= int(kage.group(1), 16) < END else {}

# the data, in the PS1's layout
def block(lo, hi_, sect):
    out = ['    ".section %s\\n"' % sect, '    ".balign 16\\n"']
    a = lo
    while a < hi_:
        if a in labels:
            out.append('    ".globl %s\\n%s:\\n"' % (lname(a), lname(a)))
        if a in ptrs:
            v = ptrs[a]
            n = lname(v) if isinstance(v, int) else v
            out.append('    ".word %s\\n"' % ABI_WRAP.get(n, n)); a += 4; continue
        nxt = min([x for x in labels if x > a] + [x for x in ptrs if x > a] + [hi_])
        if sect == '.bss':
            out.append('    ".space %d\\n"' % (nxt - a))
        else:
            out.append('    ".byte %s\\n"' % ','.join(str(x) for x in b[a - BASE:nxt - BASE]))
        a = nxt
    return out

src = ['/* Generated by tools/port/stage_split.py from the disc\'s %s: the port\'s %s (the decomp hasn\'t split it).' % (ovl, ovl),
       ' * Each function is mips2c.py\'s exact-behaviour C (recomp/). Data in the PS1\'s layout. Port only. */',
       '#ifdef MGS_PORT', '#include "recomp.h"', '', '__asm__(']
for name, lo, hi_ in regions:
    src += block(lo, hi_, '.data')
src += block(END, bss_end, '.bss')
src += ['    ".text\\n");', '']
src += ['#include "overlays/%s/recomp/%s.inc"' % (ovl, fname(a)) for a in funcs]
for f, w in ABI_WRAP.items():
    src += ['', '/* demoexec.c calls DEMOID_SHADOW with an SVECTOR by value: the EE passes it in one register, the translated code',
            '   takes the PS1\'s two (a1: vx, vy; a2: vz, pad), so every argument after it was one register off (its color as a',
            '   pointer: a TLB miss at NULL+0x48) */',
            'typedef struct { short vx, vy, vz, pad; } Ps1Svector;',
            'void *%s(void *parent, Ps1Svector v, int *arg2, int *arg3, int r, int g, int b)' % w, '{',
            '    return (void *)G_%s((int)parent, (unsigned short)v.vx | v.vy << 16, (unsigned short)v.vz | v.pad << 16,' % f,
            '                   (int)arg2, (int)arg3, r, g, b, 0, 0, 0, 0);', '}']
src += ['#endif']
os.makedirs('source/overlays/%s' % ovl, exist_ok=True)
open('source/overlays/%s/%s.c' % (ovl, ovl), 'w').write('\n'.join(src) + '\n')

# the stage table by symbol
def csym(a):
    if a in funcs: return fname(a)
    k = rkeys[bisect.bisect_right(rkeys, a) - 1]
    if k != a: raise SystemExit('stage table: %08X is no symbol' % a)
    return res[a]
inc = ['/* Generated by tools/port/stage_split.py: source/stage/%s.c\'s table by symbol, for the port. */' % ovl]
names = sorted({ABI_WRAP.get(csym(a), csym(a)) for a in ctors})
charalst = open('source/include/charalst.h').read()  # declares the resident constructors it lists (NEWCHARA)
inc += ['extern char %s[];' % n for n in names
        if n.startswith(ovl + '_') or n in ABI_WRAP.values() or not re.search(r'\b%s\b' % n, charalst)]
inc += ['CHARA _StageCharacterEntries[] = {']
for l in table.split('\n'):
    m = re.match(r'(\s*)\{ (0x[0-9a-f]+), \(NEWCHARA \*\)0x([0-9a-f]{8}) \},(.*)', l)
    if m:
        n = csym(int(m.group(3), 16))
        inc.append('%s{ %s, (NEWCHARA *)%s },%s' % (m.group(1), m.group(2), ABI_WRAP.get(n, n), m.group(4)))
    elif re.match(r'\s*(\{ 0, 0 \}|CHARA_\w+|DEMO_\w+|\{)', l) and 'CHARA _Stage' not in l:
        inc.append(l)
inc.append('};')
open('source/overlays/%s/stage_table.inc' % ovl, 'w').write('\n'.join(inc) + '\n')

if '#include "overlays/%s/stage_table.inc"' % ovl not in table:  # the original table stays for the other builds
    t2 = table.replace('CHARA _StageCharacterEntries[] = {', '#ifdef MGS_PORT\n#include "overlays/%s/stage_table.inc"\n#else\n'
                       'CHARA _StageCharacterEntries[] = {' % ovl, 1).rstrip('\n') + '\n#endif\n'
    open('source/stage/%s.c' % ovl, 'w', encoding='utf-8').write(t2)
with open('obj/linker_command_file_%s_lhs.txt' % ovl, 'w') as f:
    f.write('; generated by tools/port/stage_split.py\n')
    f.write('    include "../obj\\stage\\%s.obj", overlay\n' % ovl)
    f.write('    include "../obj\\overlays\\%s\\%s.obj", overlay\n' % (ovl, ovl))
print('%s: %d bytes; code %08X-%08X, %d functions; data %d labels, %d pointers; bss to %08X'
      % (ovl, len(b), tstart, tend, len(funcs), len(labels), len(ptrs), bss_end))
