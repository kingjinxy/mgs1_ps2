#!/usr/bin/env python3
"""The stage overlays, linked into the PS2 executable (Step 3 in docs/Planning Doc.md).

Each overlay's objects (the matching build's rendered overlay link lists, obj/linker_command_file_<ovl>_lhs.txt)
are compiled as the main executable's (build_ps2.py) and merged with `ld -r` into obj_ps2/ovl/<ovl>.o.
Every symbol the overlay defines is then made local, except its CHARA table, renamed
_StageCharacterEntries_<ovl>: so objects shared by several overlays (enemy/*.c is in dozens) are a
separate copy, with separate data, in each, as on the PS1. References to the main executable stay
undefined and resolve in the final link. obj_ps2/ovl/stages.c lists the tables by stage name for
game/chara.c's Port_SetStage, which the overlay loader (game/gamed.c GM_LoadInitBin) calls instead of
copying the binary.

An overlay is linked in only once it has no INCLUDE_ASM stubs and no literal addresses of its own code
or data (tools/port/overlay_survey.py); the rest are listed by the link. PSY-Q library objects in an
overlay's list come from the HAL instead. Each overlay's .data/.bss lie between Port_Ovl_<ovl>_* symbols, for
game/chara.c's reset when its stage is loaded.
"""
import os
import re
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "port"))
import overlay_survey  # noqa: E402
import build_ps2  # noqa: E402

ROOT, OUT = build_ps2.ROOT, build_ps2.OUT
OVL = os.path.join(OUT, "ovl")
# Objects of overlay lists with no C source, and what stands in for them in the port.
NO_SOURCE = {
    "source/safechk.c": "SafetyCheck (port/src/cdbios_ps2.c)",
}
TABLE = "_StageCharacterEntries"


def survey(name):
    """(sources, reason it can't be linked in yet or None)."""
    srcs, _ = overlay_survey.overlay_objects(name)
    stubs = lits = 0
    # jump table entries: the PS1 addresses mips2c's translated switches compare against (case 0x...:), not pointers
    recomp = os.path.join(ROOT, "source", "overlays", name, "recomp")
    cases = {c.upper() for f in (os.listdir(recomp) if os.path.isdir(recomp) else [])
             for c in re.findall(r"case 0x([0-9a-f]{8}):", open(os.path.join(recomp, f)).read())}
    for s in srcs:
        path = os.path.join(ROOT, s)
        if not os.path.exists(path):
            if s not in NO_SOURCE:
                return srcs, "no source for " + s
            continue
        text = overlay_survey.strip_comments(open(path, errors="replace").read())
        stubs += len(re.findall(r"^\s*(?:#pragma\s+)?INCLUDE_ASM", text, re.M))
        lits += len([a for a in overlay_survey.LIT.findall(text) if a.upper() not in cases])
    if stubs:
        return srcs, "%d INCLUDE_ASM" % stubs
    if lits:
        return srcs, "%d literal symbol addresses" % lits
    return [s for s in srcs if s not in NO_SOURCE], None


def build(run, objcopy, ld, cc, renames):
    """Compiles and merges the overlays that can be linked in; returns their objects (and the table's)."""
    names = sorted(os.path.basename(p)[len("linker_command_file_"):-len("_lhs.txt")]
                   for p in os.listdir(os.path.join(ROOT, "obj")) if re.match(r"linker_command_file_.+_lhs\.txt$", p))
    ready, left = {}, []
    for n in names:
        srcs, why = survey(n)
        if why:
            left.append("%s (%s)" % (n, why))
        else:
            ready[n] = srcs
    sources = sorted({s for srcs in ready.values() for s in srcs})
    with ThreadPoolExecutor(os.cpu_count()) as ex:
        failed = [s for s, rc, _ in ex.map(build_ps2.compile_one, sources) if rc]
    if failed:
        sys.exit("overlay sources failed to compile:\n  " + "\n  ".join(failed))
    os.makedirs(OVL, exist_ok=True)
    objs = []
    for n, srcs in ready.items():
        merged = os.path.join(OVL, n + ".o")
        # .data and .bss between symbols, for game/chara.c's reset on a stage load (a PS1 reload copies the overlay
        # again). Commons stay out: on the PS1 they resolve against the main executable's variables.
        script = os.path.join(OVL, n + ".ld")
        with open(script, "w") as f:
            f.write("SECTIONS {\n  .data : { Port_Ovl_%s_data = .; *(.data .data.*) Port_Ovl_%s_data_end = .; }\n"
                    "  .bss : { Port_Ovl_%s_bss = .; *(.bss .bss.*) Port_Ovl_%s_bss_end = .; }\n}\n" % ((n,) * 4))
        r = run([ld, "-r", "-T", script, "-o", merged, *[os.path.join(OUT, s[len("source/"):-2] + ".o") for s in srcs]],
                check=False)
        if r.returncode:
            sys.exit("overlay %s doesn't link together:\n%s" % (n, r.stderr[-3000:]))
        run([objcopy, *[a for r in renames + ["%s=%s_%s" % (TABLE, TABLE, n)] for a in ("--redefine-sym", r)], merged])
        run([objcopy, *["--keep-global-symbol=" + k for k in ["%s_%s" % (TABLE, n)] +
                        ["Port_Ovl_%s_%s" % (n, e) for e in ("data", "data_end", "bss", "bss_end")]], merged])
        objs.append(merged)
    table = os.path.join(OVL, "stages.c")
    with open(table, "w") as f:
        f.write("/* Generated by build/overlays_ps2.py: the overlays linked in, by stage name (game/chara.c). */\n")
        f.writelines("extern char %s_%s[], Port_Ovl_%s_data[], Port_Ovl_%s_data_end[], Port_Ovl_%s_bss[], Port_Ovl_%s_bss_end[];\n"
                     % ((TABLE, n) + (n,) * 4) for n in ready)
        f.write("struct { const char* name; void* charas; char *data, *data_end, *bss, *bss_end; void* initial; } Port_Stages[] = {\n")
        f.writelines('    { "%s", %s_%s, Port_Ovl_%s_data, Port_Ovl_%s_data_end, Port_Ovl_%s_bss, Port_Ovl_%s_bss_end, 0 },\n'
                     % ((n, TABLE, n) + (n,) * 4) for n in ready)
        f.write("    { 0 }\n};\n")
    run([cc, "-c", "-O2", "-G0", table, "-o", table[:-2] + ".o"])
    print("overlays linked in: %d: %s" % (len(ready), " ".join(ready)))
    print("overlays left out: %d: %s" % (len(left), ", ".join(left)))
    return objs + [table[:-2] + ".o"]
