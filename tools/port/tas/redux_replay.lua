-- TAS control run in PCSX-Redux (docs/TAS Testing Plan.md): the PS1 game under the port's replay harness
-- (port/src/tas_replay.c), from the same tables (tools/port/tas/trace_to_pads.py), with execute breakpoints where the
-- port has its hooks. Its trace (the port's format) compared with BizHawk's shows what the harness gets wrong; the
-- port compared with it shows the port's own differences. The stream start gate jumps over strctrl.c's
-- case 2, and the stream data gate is the PS1's disc timing (FS_StreamGetData).
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
local REC = 40
local function time_rec(t) if t < 0 or (t + 1) * REC > #TIME then return nil end; return t * REC end

-- PS1 addresses (obj/asm.map, and the returns read from the executable)
local GV_TIME, GV_CLOCK, GV_PASSAGE, GM_STATUS, SEED = 0x800AB330, 0x800AB920, 0x800AB924, 0x800AB3CC, 0x800C1530
local GV_PADDATA, PAD_RAW, PAD_STATE, POS, ALERT, LOADREQ, UNDRAW = 0x800B05C0, 0x800C14E0, 0x800C14F0, 0x800ABA10, 0x800ABA00, 0x800AB3D0, 0x800AB380
local LINKVAR, STAGE, PSTATUS, PCTRL, MTS_TIME = 0x800B4D98, 0x800AB3C4, 0x800ABA50, 0x800AB9F4, 0x800A3D78

-- the PS1 load ends in the tables: loops whose line has GM_LoadRequest back to 0
local load_ends, prev = {}, 0
for t = 0, #TIME / REC - 1 do local r = le(TIME, t * REC + 8); if prev ~= 0 and r == 0 then load_ends[#load_ends + 1] = t end; prev = r end

local out = assert(io.open(OUT, "w"))
-- per loop, whether its pad update ran in the video frame in which GV_Time became N (then BizHawk's line N, taken
-- at that frame's end, has loop N's pads) or after a vertical blank (line N has loop N-1's): "t same|later"
local phase = assert(io.open(os.getenv("TAS_PHASE") or (dir .. "/redux_phase.txt"), "w"))
local act_vbl, act_time = -1, -1
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

-- The pads: at GV_UpdatePadSystem's entry, mts's raw pads (pad_800C14E0) become the controller the PS1 game read in
-- this loop, rebuilt from the recorded GV_PadData: [2]/[3].status are mts_PadRead's buttons (with the stick's d-pad
-- bits added when the pad is in analog mode: cleared then), [0]/[1] hold the sticks. The game then computes
-- GV_PadData itself: a loop can update the pads twice (dgd.c, then a script's pad command at a codec's end, with
-- STATE_PADRELEASE cleared in between), and writing the recorded result at both gave Snake the stick a call early.
local function s16(s, o) local v = s:byte(o + 1) + s:byte(o + 2) * 256; return v >= 0x8000 and v - 0x10000 or v end
bp(0x8001682C, "tas pads", function()            -- GV_UpdatePadSystem's entry
  if u32(GV_TIME) == act_time then
    phase:write(string.format("%d %s\n", act_time, u32(MTS_TIME) == act_vbl and "same" or "later"))
    act_time = -1
  end
  local o = lookup(PADS, 68, u32(GV_TIME))
  if not o then return end
  for port = 0, 1 do
    local buttons = s16(PADS, o + (2 + port) * 16) % 0x10000
    local analog = s16(PADS, o + port * 16 + 10)
    if analog > 0 then buttons = bit.band(buttons, 0x0FFF) end
    local p = a(PAD_RAW) + port * 8
    local active = bit.band(bit.bnot(buttons), 0xFFFF)
    mem[p + 2] = active % 256; mem[p + 3] = math.floor(active / 256)
    -- the sticks whenever the raw pad is analog: a held d-pad clears GV_PadData's analog, but the game still copies
    -- them (loop 2,462)
    if analog > 0 or mem[p] > 1 then for i = 0, 3 do mem[p + 4 + i] = PADS:byte(o + port * 16 + 12 + i + 1) end end
  end
end)
if os.getenv("TAS_NO_RAW") == nil then bp(0x8008C090, "tas raw pads", function()        -- do_control's return (vertical blank)
  local o = lookup(RAW, 28, u32(GV_TIME))
  if o then
    for i = 0, 15 do mem[a(PAD_RAW) + i] = RAW:byte(o + i + 1) end
    for i = 0, 7 do mem[a(PAD_STATE) + i] = RAW:byte(o + 16 + i + 1) end
  end
end) end
-- strctrl.c's case 2, as Capture_StreamMayStart: no stream start while we've started as many as the PS1 had by
-- this loop (counted at FS_StreamTickStart; STATE_VOX_STREAM comes earlier, when the actor is made)
local starts = 0
bp(0x800243D8, "tas stream start", function() starts = starts + 1 end)
if os.getenv("TAS_NO_GATE") == nil then bp(0x80037894, "tas stream gate", function()
  local r = time_rec(u32(GV_TIME))
  if r and starts >= le(TIME, r + 28) then PCSX.getRegisters().pc = 0x80037AD0 end   -- the case's break
end) end
-- FS_StreamGetTick: the PS1's value; with its stream clock not started (NO_TICK, fs_stream_last_time -1) it returned
-- mts_time + 1, so a packet went as soon as its data was in
bp(0x800244D4, "tas tick", function()            -- FS_StreamGetTick's return
  local r = time_rec(u32(GV_TIME))
  if not r then return end
  local tick = le(TIME, r)
  PCSX.getRegisters().GPR.n.v0 = tick ~= NO_TICK and tick or (u32(MTS_TIME) + 1) % 0x100000000
end)
-- FS_StreamGetData looks through the packets from fs_stream_top to fs_stream_bottom (the data in from the disc so
-- far); the disc's timing differs between emulators, so it stops at the PS1's bottom when this one has got further
-- (the PS1's is then one of the packets before ours). At the beq after its load (and the load delay), v1 holds
-- fs_stream_bottom.
local HEAP, HEAP_SIZE, TOP = 0x800B52A4, 0x800B52AC, 0x800B52B4
local function packet_before(from, to, want)      -- whether `want` is on the packet chain from `from` to `to`
  local heap, size, p = u32(HEAP), u32(HEAP_SIZE), from
  for _ = 1, 4096 do
    if p == want then return true end
    if p == to then return false end
    local tag = u32(p)
    if tag % 256 == 0xFF then p = heap
    else
      p = p + math.floor(tag / 256)
      if p >= heap + size then p = heap end
    end
  end
  return false
end
if os.getenv("TAS_NO_DATA_GATE") == nil then bp(0x8002411C, "tas stream data", function()
  local r = time_rec(u32(GV_TIME))
  local heap = u32(HEAP)
  if not r or heap == 0 then return end
  local off = le(TIME, r + 24)
  if off >= 0x80000000 then return end            -- -1: no stream heap on the PS1
  local regs = PCSX.getRegisters().GPR.n
  local bottom, want = u32(0x800B52BC), heap + off
  if want ~= bottom and packet_before(u32(TOP), bottom, want) then regs.v1 = want end
end) end
-- FS_LoadFileSync (the codec's radio data, some overlays): still reading while the PS1 was, when ours has finished
-- (returns at once with the PS1's bytes to come). Opt-in (TAS_FILE_GATE): at the intro's codec (loop 816) it moved
-- the extra rand() from 820 to 840 and lost the skip; the PS1's CD task was still the ended stream's then
-- (0x7FFF0000 to come), so its codec read waited behind it: not modelled yet.
if os.getenv("TAS_FILE_GATE") then bp(0x80021F48, "tas file read", function()
  local r = time_rec(u32(GV_TIME))
  if not r then return end
  local left = le(TIME, r + 32)
  -- not a file's size (0x7FFF0000: the CD task a stream left, which reads until stopped): no gate
  if left == 0 or left >= 0x1000000 or u32(0x800B4E74) ~= 0 then return end
  local regs = PCSX.getRegisters()
  regs.GPR.n.v0 = left; regs.pc = regs.GPR.n.ra
end) end
bp(0x8002E460, "tas load start", function() load_flag = true end)   -- NewLoader
bp(0x8002E458, "tas load end", function() load_flag = true end)     -- loader.c's Die
bp(0x80014BD0, "tas loop", function()            -- gvd.c's Act return: as Port_TasPassageTime and Port_TasTrace
  local t = u32(GV_TIME)
  local r = time_rec(t)
  if r then w32(GV_PASSAGE, le(TIME, r + 12)) end
  if t == traced then return end
  act_vbl = u32(MTS_TIME)
  local request = u32(LOADREQ)
  if prev_request ~= 0 and request == 0 and loads <= #load_ends then
    if t ~= load_ends[loads] then
      print(string.format("tas: load end %d at loop %d, the PS1's at %d", loads - 1, t, load_ends[loads]))
      t = load_ends[loads]; w32(GV_TIME, t)
    end
    r = time_rec(t)
    if r then w32(GV_PASSAGE, le(TIME, r + 12)); w32(GV_CLOCK, le(TIME, r + 20)); w32(0x800AB9E8, le(TIME, r + 36))
      local m = math.floor(le(TIME, r + 36) / 60)  -- GM_PlayTimeHours/Seconds (linkvarbuf[91]/[92]), as gamed.c's Act
      local hm, sm = math.floor(m / 3600), m % 3600
      mem[a(LINKVAR) + 182] = hm % 256; mem[a(LINKVAR) + 183] = math.floor(hm / 256)
      mem[a(LINKVAR) + 184] = sm % 256; mem[a(LINKVAR) + 185] = math.floor(sm / 256)
    end
    loads = loads + 1; load_flag = true
  end
  -- a load requested: not every load goes through loader.c (s00a's at loop 917), and the stage's actors made before
  -- its end (the rats) draw from the seed
  if prev_request == 0 and request ~= 0 then load_flag = true end
  prev_request = request
  if load_flag and r then w32(SEED, le(TIME, r + 16)) end
  load_flag = false
  traced = t
  act_time = t                                    -- after a realign: the loop's number as the PS1's
  local stage = ""
  for i = 0, 7 do local c = u8(STAGE + i); if c == 0 then break end; stage = stage .. string.char(c) end
  local ctrl = u32(PCTRL)
  local okc = ctrl >= 0x80000000 and ctrl < 0x80200000
  out:write(string.format("%d %d %d %d %08x %08x %s %s %s %s %d %d %d %s - - - - - - - - %08x %s %s\n",
    u32(MTS_TIME), t, s32(GV_CLOCK), s32(GV_PASSAGE), u32(GM_STATUS), u32(SEED), stage == "" and "-" or stage,
    hex(GV_PADDATA, 64), hex(PAD_RAW, 16), hex(POS, 8), s32(ALERT), s32(LOADREQ), s32(UNDRAW), hex(LINKVAR, 192),
    u32(PSTATUS), okc and hex(ctrl, 124) or "-", okc and hex(ctrl - 0x20 + 0x9B0, 192) or "-"))
  if t % 64 == 0 then out:flush(); print(string.format("tas: loop %d %s", t, stage)) end
  if t % 64 == 0 then phase:flush() end
  if t >= LAST then out:write("END\n"); out:close(); phase:close(); PCSX.quit(0) end
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
