"""tools/port/fdiff.py OVERLAY FUNC: the function's words (asm/overlays/OVL/FUNC.s) found in build/OVL.matching.bin, against the
same range of obj/OVL.bin (the build); prints the differing instructions, disassembled, with a little context."""
import re, struct, subprocess, sys, tempfile
ovl, fn = sys.argv[1], sys.argv[2]
want = [int(m, 16) for m in re.findall(r'dw 0x([0-9A-F]{8})', open('asm/overlays/%s/%s.s' % (ovl, fn)).read())]
ref = open('build/%s.matching.bin' % ovl, 'rb').read()
got = open('obj/%s.bin' % ovl, 'rb').read()
off = ref.find(struct.pack('<%dI' % len(want), *want))
if off < 0:
    sys.exit('not found in the matching binary')
addr = int(fn.split('_')[-1], 16)
def dis(words):
    with tempfile.NamedTemporaryFile(suffix='.bin') as f:
        f.write(struct.pack('<%dI' % len(words), *words)); f.flush()
        out = subprocess.run([sys.argv[3] if len(sys.argv) > 3 else '/home/alex/ps2dev/ee/bin/mips64r5900el-ps2-elf-objdump',
                              '-D', '-b', 'binary', '-mmips:3000', '-EL', '--adjust-vma=0x%x' % addr, f.name],
                             capture_output=True, text=True).stdout
    return [l for l in out.splitlines() if re.match(r'^\s*[0-9a-f]+:\t', l)]
gotw = list(struct.unpack_from('<%dI' % len(want), got, off))
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
