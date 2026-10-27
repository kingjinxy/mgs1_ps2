#!/usr/bin/env python3
"""Per overlay: its objects (from the matching build's rendered linker command files), INCLUDE_ASM
stubs in their sources, and literal symbol addresses (find_fixed_addresses.py --symbols) in them.

    python3 tools/port/overlay_survey.py [overlay ...]
"""
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OBJ = os.path.join(ROOT, "obj")
# Code/data addresses (0x80010000 up to MEM_ADDR); not flag bits like 0x80000000.
LIT = re.compile(r"(?<![\w])0x(800[1-9A-Fa-f][0-9A-Fa-f]{4}|8010[0-9A-Fa-f]{4}|8011[0-6][0-9A-Fa-f]{3})\b")


def overlay_objects(name):
    """(game sources, PSY-Q library objects) of an overlay."""
    srcs, libs = [], []
    for line in open(os.path.join(OBJ, "linker_command_file_%s_lhs.txt" % name), errors="replace"):
        m = re.match(r'\s*include\s+"([^"]+)"\s*,\s*overlay', line, re.I)
        if m:
            p = m.group(1).replace("\\", "/")
            if "/psyq_4.4/" in p:
                libs.append(os.path.basename(p))
            else:
                srcs.append("source/" + p.split("/obj/", 1)[1][:-4] + ".c")
        m = re.match(r'\s*inclib\s+"([^"]+)"\s*,\s*overlay', line, re.I)
        if m:
            libs.append(m.group(1))
    return srcs, libs


def strip_comments(text):
    return re.sub(r"//[^\n]*|/\*.*?\*/", " ", text, flags=re.S)


def main():
    names = sys.argv[1:] or sorted(os.path.basename(p)[len("linker_command_file_"):-len("_lhs.txt")]
                                   for p in glob.glob(os.path.join(OBJ, "linker_command_file_*_lhs.txt")))
    print("%-9s %5s %6s %6s %6s  %s" % ("overlay", "objs", "stubs", "lits", "table", "libs"))
    for n in names:
        srcs, libs = overlay_objects(n)
        stubs = lits = table = 0
        for s in srcs:
            path = os.path.join(ROOT, s)
            if not os.path.exists(path):
                continue
            text = strip_comments(open(path, errors="replace").read())
            stubs += len(re.findall(r"^\s*(?:#pragma\s+)?INCLUDE_ASM", text, re.M))
            k = len(LIT.findall(text))
            if s.startswith("source/stage/"):
                table += k
            else:
                lits += k
        print("%-9s %5d %6d %6d %6d  %s" % (n, len(srcs), stubs, lits, table, " ".join(libs)))


if __name__ == "__main__":
    main()
