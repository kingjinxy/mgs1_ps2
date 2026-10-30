-- TAS control run in PCSX-Redux (docs/TAS Testing Plan.md): the PS1 game under the port's replay harness
-- (port/src/tas_replay.c), from the same tables (tools/port/tas/trace_to_pads.py), with execute breakpoints where the
-- port has its hooks. Its trace (the port's format) compared with BizHawk's shows what the harness gets wrong; the
-- port compared with it shows the port's own differences. Not done here: the stream start gate (needs a code patch).
--
-- pcsx-redux -no-ui -debugger -run -bios=ps-10j.bin -memcard1=card1.mcd -iso=disc1.cue -dofile=redux_replay.lua
-- Environment: TAS_DIR (the tables, default ~/emu/tas), TAS_OUT (default TAS_DIR/redux_trace.log), TAS_LAST (stop at
-- this GV_Time, default 1300).

local ffi = require("ffi")
local dir = os.getenv("TAS_DIR") or (os.getenv("HOME") .. "/emu/tas")
local OUT = os.getenv("TAS_OUT") or (dir .. "/redux_trace.log")
local LAST = tonumber(os.getenv("TAS_LAST") or "") or 1300

local mem = PCSX.getMemPtr()
local function a(addr) return bit.band(addr, 0x1FFFFF) end
local function u8(addr) return mem[a(addr)] end
local function u32(addr) local p = a(addr); return mem[p] + mem[p + 1] * 256 + mem[p + 2] * 65536 + mem[p + 3] * 16777216 end
local function s32(addr) local v = u32(addr); return v >= 0x80000000 and v - 0x100000000 or v end
local function w32(addr, v) local p = a(addr); v = v % 0x100000000
  mem[p] = v % 256; mem[p + 1] = math.floor(v / 256) % 256; mem[p + 2] = math.floor(v / 65536) % 256; mem[p + 3] = math.floor(v / 16777216) end
local function hex(addr, n) local t = {}; for i = 0, n - 1 do t[#t + 1] = string.format("%02x", u8(addr + i)) end; return table.concat(t) end

local function load(name)
  local f = assert(io.open(dir .. "/" .. name, "rb")); local s = f:read("*a"); f:close(); return s
end
local function le(s, o) local b1, b2, b3, b4 = s:byte(o + 1, o + 4); return b1 + b2 * 256 + b3 * 65536 + b4 * 16777216 end
local PADS, RAW, TIME = load("pads.bin"), load("raw.bin"), load("time.bin")
local NO_TICK = 0x80000000

-- the record in a change table (u32 GV_Time + data) that applies at `t`
local function lookup(tab, size, t)
  local lo, hi = 0, #tab / size - 1
  if hi < 0 or le(tab, 0) > t then return nil end
  while lo < hi do local mid = math.floor((lo + hi + 1) / 2); if le(tab, mid * size) <= t then lo = mid else hi = mid - 1 end end
  return lo * size + 4
end
local function time_rec(t) if t < 0 or (t + 1) * 24 > #TIME then return nil end; return t * 24 end

-- PS1 addresses (obj/asm.map, and the returns read from the executable)
local GV_TIME, GV_CLOCK, GV_PASSAGE, GM_STATUS, SEED = 0x800AB330, 0x800AB920, 0x800AB924, 0x800AB3CC, 0x800C1530
local GV_PADDATA, PAD_RAW, PAD_STATE, POS, ALERT, LOADREQ, UNDRAW = 0x800B05C0, 0x800C14E0, 0x800C14F0, 0x800ABA10, 0x800ABA00, 0x800AB3D0, 0x800AB380
local LINKVAR, STAGE, PSTATUS, PCTRL, MTS_TIME = 0x800B4D98, 0x800AB3C4, 0x800ABA50, 0x800AB9F4, 0x800A3D78

-- the PS1 load ends in the tables: loops whose line has GM_LoadRequest back to 0
local load_ends, prev = {}, 0
for t = 0, #TIME / 24 - 1 do local r = le(TIME, t * 24 + 8); if prev ~= 0 and r == 0 then load_ends[#load_ends + 1] = t end; prev = r end

local out = assert(io.open(OUT, "w"))
local loads, prev_request, load_flag, traced = 1, 0, false, -1
TAS_BREAKPOINTS = {}  -- global: Redux drops a breakpoint when its handle is garbage-collected
local hits, errors = {}, 0
local function bp(addr, name, fn)
  hits[name] = 0
  TAS_BREAKPOINTS[#TAS_BREAKPOINTS + 1] = PCSX.addBreakpoint(addr, "Exec", 4, name, function(...)
    hits[name] = hits[name] + 1
    local ok, err = pcall(fn, ...)
    if not ok and errors < 5 then errors = errors + 1; print("tas: error in " .. name .. ": " .. tostring(err)) end
  end)
end

bp(0x80016C70, "tas pads", function()            -- GV_UpdatePadSystem's return
  local o = lookup(PADS, 68, u32(GV_TIME))
  if o then for i = 0, 63 do mem[a(GV_PADDATA) + i] = PADS:byte(o + i + 1) end end
end)
if os.getenv("TAS_NO_RAW") == nil then bp(0x8008C090, "tas raw pads", function()        -- do_control's return (vertical blank)
  local o = lookup(RAW, 28, u32(GV_TIME))
  if o then
    for i = 0, 15 do mem[a(PAD_RAW) + i] = RAW:byte(o + i + 1) end
    for i = 0, 7 do mem[a(PAD_STATE) + i] = RAW:byte(o + 16 + i + 1) end
  end
end) end
bp(0x800244D4, "tas tick", function()            -- FS_StreamGetTick's return
  local r = time_rec(u32(GV_TIME))
  if r and le(TIME, r) ~= NO_TICK then PCSX.getRegisters().GPR.n.v0 = le(TIME, r) end
end)
bp(0x8002E460, "tas load start", function() load_flag = true end)   -- NewLoader
bp(0x8002E458, "tas load end", function() load_flag = true end)     -- loader.c's Die
bp(0x80014BD0, "tas loop", function()            -- gvd.c's Act return: as Port_TasPassageTime and Port_TasTrace
  local t = u32(GV_TIME)
  local r = time_rec(t)
  if r then w32(GV_PASSAGE, le(TIME, r + 12)) end
  if t == traced then return end
  local request = u32(LOADREQ)
  if prev_request ~= 0 and request == 0 and loads <= #load_ends then
    if t ~= load_ends[loads] then
      print(string.format("tas: load end %d at loop %d, the PS1's at %d", loads - 1, t, load_ends[loads]))
      t = load_ends[loads]; w32(GV_TIME, t)
    end
    r = time_rec(t)
    if r then w32(GV_PASSAGE, le(TIME, r + 12)); w32(GV_CLOCK, le(TIME, r + 20)) end
    loads = loads + 1; load_flag = true
  end
  prev_request = request
  if load_flag and r then w32(SEED, le(TIME, r + 16)) end
  load_flag = false
  traced = t
  local stage = ""
  for i = 0, 7 do local c = u8(STAGE + i); if c == 0 then break end; stage = stage .. string.char(c) end
  local ctrl = u32(PCTRL)
  local okc = ctrl >= 0x80000000 and ctrl < 0x80200000
  out:write(string.format("%d %d %d %d %08x %08x %s %s %s %s %d %d %d %s - - - - - %08x %s %s\n",
    u32(MTS_TIME), t, s32(GV_CLOCK), s32(GV_PASSAGE), u32(GM_STATUS), u32(SEED), stage == "" and "-" or stage,
    hex(GV_PADDATA, 64), hex(PAD_RAW, 16), hex(POS, 8), s32(ALERT), s32(LOADREQ), s32(UNDRAW), hex(LINKVAR, 192),
    u32(PSTATUS), okc and hex(ctrl, 124) or "-", okc and hex(ctrl - 0x20 + 0x9B0, 192) or "-"))
  if t % 64 == 0 then out:flush(); print(string.format("tas: loop %d %s", t, stage)) end
  if t >= LAST then out:write("END\n"); out:close(); PCSX.quit(0) end
end)
print(string.format("tas: control run, %d PS1 load ends, trace to %s", #load_ends, OUT))
local vs = 0
heartbeat = PCSX.Events.createEventListener("GPU::Vsync", function()
  vs = vs + 1
  if vs % 300 == 0 then
    local h = {}
    for k, v in pairs(hits) do h[#h + 1] = k .. "=" .. v end
    print(string.format("tas: vsync %d GV_Time %d hits %s", vs, u32(GV_TIME), table.concat(h, " ")))
  end
end)
