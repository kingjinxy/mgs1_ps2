#!/usr/bin/env python3
"""PS2 link of the main executable (overlays left out): compiles the game (build_ps2.py) and the HAL,
links them against ps2sdk into obj_ps2/mgs.elf. The game's PS1 main() becomes Game_PsxMain, which the
HAL's main() (src/port_main.c) calls once the PS2 side is up.

    python3 build/link_ps2.py

The HAL's disc and memory card files are left out until MGS has its own (decision B in
docs/Planning Doc.md; the card mapping): every function nothing defines yet gets a generated stub that
logs its first calls (obj_ps2/hal_stubs.c), and the link reports them.
Environment: as build_ps2.py, plus GSKIT (default $PS2DEV/gsKit). MGS_LOG_DIRECT=1: console output
straight through (port/src/hal_game.c), for debugging before the game's vertical blank handler runs.
"""
import os
import re
import shutil
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import build_ps2  # noqa: E402

ROOT, HAL, PSYQ, OUT = build_ps2.ROOT, build_ps2.HAL, build_ps2.PSYQ, build_ps2.OUT
PS2DEV = build_ps2.PS2DEV
PS2SDK = os.environ.get("PS2SDK", os.path.join(PS2DEV, "ps2sdk"))
GSKIT = os.environ.get("GSKIT", os.path.join(PS2DEV, "gsKit"))
EE = os.path.join(PS2DEV, "ee", "bin", "mips64r5900el-ps2-elf-")
CC, LD, OBJCOPY, NM = EE + "gcc", EE + "ld", EE + "objcopy", EE + "nm"
PORT = os.path.join(ROOT, "port")

# The HAL's generic sources (its src/*.c): against PSY-Q's headers and port/hal/ (their "common.h" and
# MGS's hal_game_config.h). They include some as <psyq/...> (the SH1 decomp's layout): obj_ps2/hal_inc/psyq
# links to PSY-Q's. SH_PORT: the HAL's switches still carry the SH1 port's name.
HAL_INC = os.path.join(OUT, "hal_inc")
HAL_CFLAGS = ["-O3", "-G0", "-fno-toplevel-reorder", "-mno-check-zero-division", "-fno-strict-aliasing", "-std=gnu89",
              "-nostdinc", "-I" + os.path.join(PORT, "hal"), "-I" + HAL_INC, "-I" + os.path.join(HAL, "include"),
              "-I" + os.path.join(PSYQ, "psyq_4.4", "include"), "-D_LANGUAGE_C", "-DSH_PORT", "-DMGS_PORT"]
# The HAL's PS2 side (its src/ps2/*.c): against ps2sdk's headers.
PS2_CFLAGS = ["-O3", "-G0", "-D_EE", "-Wall", "-I" + os.path.join(PS2SDK, "ee", "include"),
              "-I" + os.path.join(PS2SDK, "common", "include"), "-I" + os.path.join(GSKIT, "include"),
              "-iquote", os.path.join(PORT, "hal"), "-iquote", os.path.join(HAL, "include")]
# Left out for now (see the docstring): SH1's disc layout and the memory card.
HAL_LEFT_OUT = {"src/ps2/libcd_ps2.c", "src/psx_card.c", "src/ps2/memcard_ps2.c"}
IRX = ("sh1agent", "sh1spu")


def run(cmd, check=True, **kw):
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace", **kw)
    if check and r.returncode:
        sys.exit("FAILED: %s\n%s" % (" ".join(cmd), (r.stdout + r.stderr)[-4000:]))
    return r


def compile_hal():
    os.makedirs(HAL_INC, exist_ok=True)
    if not os.path.islink(os.path.join(HAL_INC, "psyq")):
        os.symlink(os.path.join(PSYQ, "psyq_4.4", "include"), os.path.join(HAL_INC, "psyq"))
    objs = []
    for sub, flags in (("src", HAL_CFLAGS), ("src/ps2", PS2_CFLAGS)):
        for name in sorted(os.listdir(os.path.join(HAL, sub))):
            rel = sub + "/" + name
            if not name.endswith(".c") or rel in HAL_LEFT_OUT:
                continue
            obj = os.path.join(OUT, "hal", rel.replace("/", "_")[:-2] + ".o")
            os.makedirs(os.path.dirname(obj), exist_ok=True)
            run([CC, "-c", *flags, os.path.join(HAL, rel), "-o", obj])
            objs.append(obj)
    return objs


def compile_port():
    """MGS's side of the HAL (port/src/*.c), against ps2sdk's headers."""
    debug = ["-DMGS_LOG_DIRECT"] if os.environ.get("MGS_LOG_DIRECT") else []
    objs = []
    for name in sorted(os.listdir(os.path.join(PORT, "src"))):
        if name.endswith(".c"):
            obj = os.path.join(OUT, "port", name[:-2] + ".o")
            os.makedirs(os.path.dirname(obj), exist_ok=True)
            run([CC, "-c", *PS2_CFLAGS, *debug, os.path.join(PORT, "src", name), "-o", obj])
            objs.append(obj)
    return objs


def build_irx():
    """The HAL's IOP modules and ps2sdk's freesd.irx (libsd), embedded in the ELF with bin2c."""
    env = dict(os.environ, PS2SDK=PS2SDK, PATH=os.path.join(PS2DEV, "iop", "bin") + os.pathsep
               + os.path.join(PS2SDK, "bin") + os.pathsep + os.environ["PATH"])
    irxs = []
    for name in IRX:
        out = os.path.join(OUT, "iop", name) + "/"
        run(["make", "-s", "-C", os.path.join(HAL, "iop", name), "IOP_OBJS_DIR=" + out], env=env)
        irxs.append(os.path.join(out, name + ".irx"))
    os.makedirs(os.path.join(OUT, "iop", "freesd"), exist_ok=True)
    irxs.append(os.path.join(OUT, "iop", "freesd", "freesd.irx"))
    shutil.copy(os.path.join(PS2SDK, "iop", "irx", "freesd.irx"), irxs[-1])
    objs = []
    for irx in irxs:
        c = irx[:-4] + "_irx.c"
        run([os.path.join(PS2SDK, "bin", "bin2c"), irx, c, os.path.basename(irx)[:-4] + "_irx"])
        run([CC, "-c", "-O2", "-G0", c, "-o", c[:-2] + ".o"])
        objs.append(c[:-2] + ".o")
    return objs


LIBS = ["gskit", "dmakit", "cdvd", "pad", "mc", "eedebug", "patches"]


def library_archives():
    """The archives the final link searches: ps2sdk's and gsKit's, and the toolchain's C library."""
    sysroot = os.path.join(PS2DEV, "ee", "mips64r5900el-ps2-elf", "lib")
    dirs = [os.path.join(PS2SDK, "ee", "lib"), os.path.join(GSKIT, "lib"), sysroot]
    names = LIBS + ["c", "m", "kernel", "cglue", "pthread", "pthreadglue"]
    return [p for n in names for d in dirs for p in [os.path.join(d, "lib%s.a" % n)] if os.path.exists(p)]


def defined_names(files):
    out = run([NM, "--defined-only", *files], check=False).stdout
    return {f[2] for f in (l.split() for l in out.splitlines()) if len(f) == 3 and f[1] in "TDBRCV"}


def final_link(elf, objs):
    return run([CC, "-T", os.path.join(PORT, "linkfile"), "-L", os.path.join(PS2SDK, "ee", "lib"),
                "-Wl,-zmax-page-size=128", "-Wl,--wrap=_write", "-Wl,--wrap=SifLoadModule",
                "-Wl,--unresolved-symbols=report-all", "-o", elf, *objs,
                "-L" + os.path.join(GSKIT, "lib"), *["-l" + n for n in LIBS]], check=False)


def main():
    if build_ps2.main():
        return 1
    game = [os.path.join(OUT, s[len("source/"):-2] + ".o") for s in build_ps2.main_exe_sources()]
    combined = os.path.join(OUT, "game.o")
    r = run([LD, "-r", "-o", combined, *game], check=False)
    if r.returncode:
        print("game objects don't link together:\n" + r.stderr[-3000:])
        return 1
    # The game defines some names the PS2's libraries also have (the retail build's dummy fprintf and
    # getchar, the sound driver's random, ...): the game keeps its own under MGS_<name>, so library code
    # (ps2sdk calls printf-family and libc functions) never ends up in them.
    clashes = sorted(defined_names([combined]) & defined_names(library_archives()))
    renames = ["main=Game_PsxMain"] + ["%s=MGS_%s" % (n, n) for n in clashes]
    run([OBJCOPY, *[a for r in renames for a in ("--redefine-sym", r)], combined])
    if clashes:
        print("renamed in the game (also in the PS2 libraries): " + " ".join(clashes))

    objs = [combined, *compile_hal(), *compile_port(), *build_irx()]
    elf = os.path.join(OUT, "mgs.elf")
    r = final_link(elf, objs)
    open(os.path.join(OUT, "link.log"), "w").write(r.stderr)
    und = sorted(set(re.findall(r"undefined reference to `([^']+)'", r.stderr)))
    other = [l for l in r.stderr.splitlines() if "undefined reference" not in l and "ld returned" not in l
             and ": in function" not in l and (": error" in l.lower() or "multiple definition" in l)]
    if other:
        print("link errors:\n  " + "\n  ".join(other[:30]))
        return 1
    if r.returncode and und:
        stubs = os.path.join(OUT, "hal_stubs.c")
        with open(stubs, "w") as f:
            f.write("/* Generated by build/link_ps2.py: functions nothing provides yet; each logs its first calls. */\n"
                    "extern int printf(const char* fmt, ...);\n"
                    "static void hal_stub_log(const char* name, int* count)\n{\n"
                    "    if (*count < 3) printf(\"HAL stub: %s\\n\", name);\n    (*count)++;\n}\n"
                    "#define STUB(name) unsigned int name() { static int n; hal_stub_log(#name, &n); return 0; }\n")
            f.writelines("STUB(%s)\n" % u for u in und)
        run([CC, "-c", "-O2", "-G0", "-std=gnu89", "-fno-builtin", stubs, "-o", stubs[:-2] + ".o"])
        r = final_link(elf, objs + [stubs[:-2] + ".o"])
        open(os.path.join(OUT, "link.log"), "w").write(r.stderr)
    if r.returncode:
        print("link failed:\n" + r.stderr[-3000:])
        return 1
    print("stubbed: %d  %s" % (len(und), " ".join(und)))
    print("linked: " + elf)
    make_iso(elf)
    return 0


def make_iso(elf):
    """obj_ps2/mgs_ps2.iso: the ELF on a DVD image (the HAL's tools/mkiso.py), booted through SYSTEM.CNF.
    PCSX2 runs it as a disc; booted from host: instead, the IOP can't load the HAL's modules
    (SifExecModuleBuffer never returns). The title ID is a placeholder."""
    title = "MGSP_000.01"
    cnf = os.path.join(OUT, "SYSTEM.CNF")
    open(cnf, "w", newline="").write("BOOT2 = cdrom0:\\%s;1\r\nVER = 1.00\r\nVMODE = NTSC\r\n" % title)
    iso = os.path.join(OUT, "mgs_ps2.iso")
    run([sys.executable, os.path.join(HAL, "tools", "mkiso.py"), iso + ".tmp", "MGSPS2",
         "SYSTEM.CNF;1=" + cnf, "%s;1=%s" % (title, elf)])
    os.replace(iso + ".tmp", iso)
    print("disc image: " + iso)


if __name__ == "__main__":
    sys.exit(main())
