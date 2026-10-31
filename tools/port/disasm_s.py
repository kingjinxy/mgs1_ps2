"""disasm_s.py OVERLAY FUNC: an INCLUDE_ASM function's words (asm/overlays/OVL/FUNC.s) disassembled, calls into the
main executable named from obj/asm.map, and overlay symbols from obj/asm_OVL_lhs.map. Run from the repo root."""
import re, struct, subprocess, sys, tempfile
ovl, fn = sys.argv[1], sys.argv[2]
addr = int(fn.split('_')[-1], 16)
words = [int(m, 16) for m in re.findall(r'dw 0x([0-9A-F]{8})', open('asm/overlays/%s/%s.s' % (ovl, fn)).read())]
names = {}
for path in ('obj/asm.map', 'obj/asm_%s_lhs.map' % ovl):
    for l in open(path):
        p = l.split()
        if len(p) == 2 and re.match(r'^[0-9A-F]{8}$', p[0]):
            names.setdefault(int(p[0], 16), p[1])
with tempfile.NamedTemporaryFile(suffix='.bin') as f:
    f.write(struct.pack('<%dI' % len(words), *words)); f.flush()
    out = subprocess.run(['/home/alex/ps2dev/ee/bin/mips64r5900el-ps2-elf-objdump', '-D', '-b', 'binary', '-mmips:3000',
                          '-EL', '--adjust-vma=0x%x' % addr, f.name], capture_output=True, text=True).stdout
for l in out.splitlines():
    m = re.match(r'^\s*([0-9a-f]+):\t[0-9a-f]+ \t(.*)', l)
    if m:
        ins = m.group(2)
        j = re.search(r'jal\s+0x([0-9a-f]+)', ins)
        if j:
            ins += '   <%s>' % names.get(int(j.group(1), 16), '?')
        print(m.group(1)[-4:], ins)
