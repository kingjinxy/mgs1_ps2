#!/bin/sh
# Plays the MGS Integral TAS in BizHawk 1.11.4 under 32-bit Wine, with the sync-check Lua script loaded.
# Usage: run_bizhawk.sh [script.lua]   (default: synccheck.lua next to this file). MGS_SHOW=1 shows the window.
# Setup (docs/TAS Testing Plan.md, Phase 1): BizHawk 1.11.4 in ~/emu/bizhawk-1.11.4, Wine prefix ~/emu/wine-bizhawk,
# discs as cue/bin in ~/emu/mgs-integral, and in ~/emu/tas the movie (mgs.bk2) and mgs.xml from this folder.
# Logs go to ~/emu/tas/<script>.log.
# BizHawk rewrites config.ini on exit, so the settings are reapplied on every start.
HERE=$(dirname "$(readlink -f "$0")")
TAS=~/emu/tas
BH=~/emu/bizhawk-1.11.4
LUA=$(readlink -f "${1:-$HERE/synccheck.lua}")

if pgrep -x EmuHawk.exe >/dev/null; then
    echo "BizHawk is already running; close it first." >&2
    exit 1
fi

winpath() { echo "Z:$1" | tr / '\\'; }

python3 -I - "$BH/config.ini" "$(winpath "$LUA")" "$(winpath "$BH/Firmware/ps-10j.bin")" <<'EOF'
import json, sys
path, lua, bios = sys.argv[1:]
c = json.load(open(path))
c["DispMethod"] = 0                      # OpenGL (Direct3D's shaders don't compile under Wine)
c["SoundEnabled"] = False
c["SaveStateCompressionLevelNormal"] = 6  # checkpoints.lua: states hold the movie input log (30 MB raw)
c["FrameSkip"] = 7
c["FirmwareUserSpecifications"] = {"PSX+J": bios}
c["RecentLua"]["recentlist"] = [lua] + [p for p in c["RecentLua"]["recentlist"] if p != lua]
c["RecentLua"]["AutoLoad"] = True        # the Lua console loads the script above...
c["CommonToolSettings"]["BizHawk.Client.EmuHawk.LuaConsole"]["AutoLoad"] = True  # ...and opens at startup
json.dump(c, open(path, "w"), indent=2)
EOF

LOG=$TAS/$(basename "$LUA" .lua).log   # written by the Lua script; ends with END at the movie's last frame
rm -f "$LOG"
cd "$BH" || exit 1
WINEPREFIX=~/emu/wine-bizhawk WINEDEBUG=-all "$HERE/../offscreen" wine EmuHawk.exe \
    "--movie=$(winpath "$TAS/mgs.bk2")" "$(winpath "$TAS/mgs.xml")" >"$TAS/emuhawk.log" 2>&1 &
PID=$!

# Watchdog: a log that hasn't changed for 90 s (or never appears within 120 s) is a stall.
START=$(date +%s)
while kill -0 $PID 2>/dev/null; do
    sleep 10
    if [ -f "$LOG" ]; then AGE=$(( $(date +%s) - $(stat -c %Y "$LOG") )); LIMIT=90
    else AGE=$(( $(date +%s) - START )); LIMIT=120; fi
    if [ $AGE -gt $LIMIT ]; then
        echo "STALL: no log progress for ${AGE}s at: $(tail -1 "$LOG" 2>/dev/null)" >&2
        kill $PID; WINEPREFIX=~/emu/wine-bizhawk wineserver -k
        exit 2
    fi
done
if tail -1 "$LOG" 2>/dev/null | grep -q END; then
    echo "OK: movie played to the end ($(wc -l < "$LOG") log lines in $LOG)"
else
    echo "FAILED: BizHawk exited before the end, at: $(tail -1 "$LOG" 2>/dev/null)" >&2
    exit 1
fi
