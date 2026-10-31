"""tools/port/fdiff.py OVERLAY FUNC: the function's words (asm/overlays/OVL/FUNC.s) found in build/OVL.matching.bin, against the
same range of obj/OVL.bin (the build); prints the differing instructions, disassembled, with a little context."""
import re, struct, subprocess, sys, tempfile
args = [a for a in sys.argv[1:] if a != '--loose']
loose = '--loose' in sys.argv  # instruction shapes only: addresses, offsets and branch targets masked (a function
                               # of another length shifts everything after it)
ovl, fn = args[0], args[1]
want = [int(m, 16) for m in re.findall(r'dw 0x([0-9A-F]{8})', open('asm/overlays/%s/%s.s' % (ovl, fn)).read())]
ref = open('build/%s.matching.bin' % ovl, 'rb').read()
import glob, os
newest = max((os.path.getmtime(f) for f in glob.glob('source/**/*.[ch]', recursive=True)), default=0)
if newest > os.path.getmtime('obj/%s.bin' % ovl):
    print('WARNING: obj/%s.bin is older than the sources (did the build fail?)' % ovl)
got = open('obj/%s.bin' % ovl, 'rb').read()
off = ref.find(struct.pack('<%dI' % len(want), *want))
if off < 0:
    sys.exit('not found in the matching binary')
addr = int(fn.split('_')[-1], 16)
def dis(words):
    with tempfile.NamedTemporaryFile(suffix='.bin') as f:
        f.write(struct.pack('<%dI' % len(words), *words)); f.flush()
        out = subprocess.run(['/home/alex/ps2dev/ee/bin/mips64r5900el-ps2-elf-objdump',
                              '-D', '-b', 'binary', '-mmips:3000', '-EL', '--adjust-vma=0x%x' % addr, f.name],
                             capture_output=True, text=True).stdout
    return [l for l in out.splitlines() if re.match(r'^\s*[0-9a-f]+:\t', l)]
gotw = list(struct.unpack_from('<%dI' % len(want), got, off))
if loose:
    import difflib
    def shape(l):
        t = l.split('\t', 2)[-1]
        t = re.sub(r'0x[0-9a-f]+', 'X', t)
        t = re.sub(r'-?\d+\(', 'N(', t)
        return re.sub(r',-?\d+$', ',N', t)
    a, b = [shape(x) for x in dis(want)], [shape(x) for x in dis(gotw + list(struct.unpack_from('<16I', got, off + 4 * len(want))))]
    sm = difflib.SequenceMatcher(None, a, b[:len(a) + 16], autojunk=False)
    n = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag != 'equal':
            n += 1
            print('%s at %d: %s | %s' % (tag, i1, ' ; '.join(a[i1:i2])[:90], ' ; '.join(b[j1:j2])[:90]))
    print('%s: %d words, %d shape differences' % (fn, len(want), n))
    sys.exit(0)
bad = [i for i in range(len(want)) if want[i] != gotw[i]]
print('%s: %d words, %d differ' % (fn, len(want), len(bad)))
if bad:
    a, b = dis(want), dis(gotw)
    shown = set()
    for i in bad[:12]:
        for j in range(max(0, i - 2), min(len(want), i + 3)):
            if j in shown: continue
            shown.add(j)
            print(('*' if j in bad else ' '), a[j].split('\t', 1)[1][:44].ljust(44), '|', b[j].split('\t', 2)[-1][:40])
