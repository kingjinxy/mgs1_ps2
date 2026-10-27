#!/usr/bin/env python3
"""PS2 (EE) build of the main executable: compiles its C files (the objects obj/linker_command_file.txt
lists before the overlay sections) with ps2dev's GCC under MGS_PORT, into obj_ps2/. Leaves the matching
build (build.py, obj/) alone.

    python3 build/build_ps2.py [--jobs N] [--only <path substring>]

Prints the files that failed (their logs: obj_ps2/<file>.log) and a count of warnings by kind.
Environment: PS2DEV (default ~/ps2dev), MGS_HAL (default ../psx-to-ps2-HAL), PSYQ_SDK (default ../psyq_sdk).
"""
import argparse
import collections
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
PS2DEV = os.environ.get("PS2DEV", os.path.expanduser("~/ps2dev"))
HAL = os.path.normpath(os.path.join(ROOT, os.environ.get("MGS_HAL", "../psx-to-ps2-HAL")))
PSYQ = os.path.normpath(os.path.join(ROOT, os.environ.get("PSYQ_SDK", "../psyq_sdk")))
CC = os.path.join(PS2DEV, "ee", "bin", "mips64r5900el-ps2-elf-gcc")
OUT = os.path.join(ROOT, "obj_ps2")

# Include order: the port's shims first (they #include_next the game's own headers), the HAL's headers,
# the game's, then Sony's PSY-Q 4.4 headers as the PS1 build uses them.
INCLUDES = [os.path.join(ROOT, "port", "include"), os.path.join(HAL, "include"), os.path.join(ROOT, "source"),
            os.path.join(ROOT, "source", "include"), os.path.join(PSYQ, "psyq_4.4", "include")]

# Decompiled PS1 code needs: NULL reads stay reads, loops keep their counts (arrays declared smaller
# than used), top-level order kept; GCC 14's new errors for old C are warnings (as in the SH1 port).
CFLAGS = ["-O2", "-G0", "-std=gnu89", "-nostdinc", "-fno-strict-aliasing", "-fno-toplevel-reorder",
          "-mno-check-zero-division", "-fno-delete-null-pointer-checks", "-fno-isolate-erroneous-paths-dereference",
          "-fno-aggressive-loop-optimizations", "-fcommon",  # tentative definitions in several files merge, as with the PS1's GCC
          "-fexec-charset=EUC-JP",  # the PS1 build converts sources to EUC-JP
          "-Wno-error=implicit-function-declaration", "-Wno-error=int-conversion",
          "-Wno-error=incompatible-pointer-types", "-Wno-error=implicit-int", "-Wno-error=return-mismatch",
          "-D_LANGUAGE_C", "-DLANGUAGE_C", "-DMGS_PORT", "-DINTEGRAL"]


def main_exe_sources():
    """The main executable's C files, in link order, from the matching build's rendered link list
    (obj/linker_command_file.txt: the main_exe variant, so no VR or dev objects)."""
    path = os.path.join(ROOT, "obj", "linker_command_file.txt")
    if not os.path.exists(path):
        sys.exit("no %s: run the matching build (build.py) first" % path)
    text = open(path).read().split("section .rdata")[0]
    sources = []
    for obj in re.findall(r'include\s+"\.\./obj\\([^"\s]+)\.obj', text):  # one line lacks its closing quote
        path = os.path.join("source", obj.replace("\\", "/") + ".c")
        if not os.path.exists(os.path.join(ROOT, path)):
            sys.exit("no source for %s" % obj)
        sources.append(path)
    return sources


def compile_one(src):
    obj = os.path.join(OUT, src[len("source/"):-2] + ".o")
    log = obj[:-2] + ".log"
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    cmd = [CC, "-c", *CFLAGS, *["-I" + i for i in INCLUDES], os.path.join(ROOT, src), "-o", obj]
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    open(log, "w").write(r.stdout + r.stderr)
    return src, r.returncode, r.stderr


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    ap.add_argument("--only", default="")
    args = ap.parse_args()
    sources = [s for s in main_exe_sources() if args.only in s]
    with ThreadPoolExecutor(args.jobs) as ex:
        results = list(ex.map(compile_one, sources))
    failed = [s for s, rc, _ in results if rc]
    warnings = collections.Counter(w for _, _, err in results for w in re.findall(r"\[-W([a-z0-9-=]+)\]", err))
    print("compiled %d of %d main executable files" % (len(sources) - len(failed), len(sources)))
    for s in failed:
        print("  failed: %s" % s)
    for w, n in warnings.most_common():
        print("  warnings %6d  -W%s" % (n, w))
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
