"""symlits.py OVL FILE...: literal PS1 addresses in an overlay's data initializers -> (int)SYMBOL from the link map;
words a translated switch compares against (case 0x...: in recomp/) stay literal."""
import os, re, sys
sys.path.insert(0, 'tools/port')
import overlay_survey
ovl = sys.argv[1]
names = {}
for l in open('obj/asm_%s_lhs.map' % ovl, errors='ignore'):
    p = l.split()
    if len(p) == 2 and re.match(r'^[0-9A-F]{8}$', p[0]):
        names.setdefault(int(p[0], 16), p[1])
rec = 'source/overlays/%s/recomp' % ovl
cases = {int(c, 16) for f in os.listdir(rec) for c in re.findall(r'case 0x([0-9a-f]{8}):', open(os.path.join(rec, f)).read())}
for path in sys.argv[2:]:
    t = open(path, errors='surrogateescape').read()
    need = set()
    def rep(m):
        a = int(m.group(2), 16)
        if a in cases or a not in names:
            if a not in cases: print('%s: no symbol at %08X' % (path, a))
            return m.group(0)
        n = names[a]
        if not re.search(r'\b%s\b' % n, t): need.add(n)
        return m.group(1) + ('(int)%s' % n if m.group(1).endswith('= ') or m.group(1).endswith('{ ') or m.group(1).strip() == '' else n)
    new = re.sub(r'(= |\(NEWCHARA \*\)|^\s*)0x(8[0-9a-fA-F]{7})\b', rep, t, flags=re.M)
    if need:
        decl = ''.join('extern char %s[];\n' % n for n in sorted(need))
        i = list(re.finditer(r'^#include.*\n', new, re.M))[-1].end()
        new = new[:i] + '\n' + decl + new[i:]
    open(path, 'w', errors='surrogateescape').write(new)
    print(path, len(need), 'declared')
