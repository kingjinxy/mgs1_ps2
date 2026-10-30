-- Per-game-frame trace of the MGS Integral TAS (TAS Testing Plan, Phase 2).
-- One line each time GV_Time changes (one pass of the game loop), fields separated by spaces:
--   movie frame, GV_Time, GV_Clock, GV_PassageTime, GM_GameStatus, rand seed, stage name,
--   GV_PadData[0..3] (hex, 4x16 bytes: the pads as the game read them this loop; [2..3] are the raw ones), mts pads pad_800C14E0[0..1] (hex, 2x8 bytes),
--   GM_PlayerPosition (hex, 8 bytes), GM_AlertMode, GM_LoadRequest, DG_UnDrawFrameCount,
--   linkvarbuf (hex, 96 shorts: the save state),
--   mts_time (the vertical blank count), fs_stream_last_time, fs_stream_next_time (libfs/stream.c's statics:
--   with mts_time, what FS_StreamGetTick returned this loop; BizHawk 1.11.4 has no execute callbacks for PSX),
--   pad_state_800C14F0[0..1] (hex, 2 ints: mts's pad init states, behind mts_get_pad_vibration_type),
--   the game task's (mts task 3, dgd.c's mts_wait_vbl) last wake and target vertical blank and GV_LastTickCount (the
--   vertical blank of this loop's GV_Time++), "last:target:tick": with mts_time, whether this line is from before
--   or after the loop's pad update (tools/port/tas/trace_to_pads.py),
--   how far a stream's data had come in from the disc: fs_stream_bottom - fs_stream_heap (libfs/stream.c; -1 with
--   no stream heap; FS_StreamGetData doesn't look past it),
--   the CD file read's bytes still to come (cdbios_task.remaining * 4 at 0x800B4E74: what FS_LoadFileSync returns),
--   gTotalFrameTime (gamed.c: the play time in vertical blanks, behind GM_PlayTimeHours/Seconds)
-- Addresses: obj/asm.map of the matching build (SLPM-86247). Ends with END at the movie's last frame.
local OUT   = "Z:\\home\\alex\\emu\\tas\\trace.log"
local LAST  = 313202
local RAM   = "MainRAM"

local function a(addr) return addr % 0x200000 end
local function u32(addr) return memory.read_u32_le(a(addr), RAM) end
local function s32(addr) local v = u32(addr); return v >= 0x80000000 and v - 0x100000000 or v end
local function hex(addr, len)
  local t = memory.readbyterange(a(addr), len, RAM)
  local s = {}
  for i = 0, len - 1 do s[#s + 1] = string.format("%02x", t[i] or 0) end
  return table.concat(s)
end
local function name(addr)
  local s = ""
  for i = 0, 7 do
    local c = memory.readbyte(a(addr + i), RAM)
    if c == 0 then break end
    s = s .. string.char(c)
  end
  return s == "" and "-" or s
end

-- the game task's mts_wait_vbl state (mts_tasks_800C0C30[3].intr: last, target)
local function wait()
  local intr = u32(0x800C0C30 + 3 * 32 + 4)
  if intr < 0x80000000 or intr >= 0x80200000 then return "-" end
  return string.format("%d:%d:%d", u32(intr + 8), u32(intr + 12), u32(0x800AB334))
end

-- fs_stream_bottom's offset in the stream heap (fs_stream_heap 0x800B52A4, fs_stream_bottom 0x800B52BC)
local function bottom()
  local heap = u32(0x800B52A4)
  if heap == 0 then return -1 end
  return u32(0x800B52BC) - heap
end

local out = io.open(OUT, "w")
emu.limitframerate(false)
local prev = -1
while true do
  local f = emu.framecount()
  local t = u32(0x800AB330)                       -- GV_Time
  if t ~= prev then
    prev = t
    out:write(string.format("%d %d %d %d %08x %08x %s %s %s %s %d %d %d %s %d %d %d %s %s %d %d %d\n",
      f, t, u32(0x800AB920), u32(0x800AB924), u32(0x800AB3CC), u32(0x800C1530), name(0x800AB3C4),
      hex(0x800B05C0, 64), hex(0x800C14E0, 16), hex(0x800ABA10, 8),
      u32(0x800ABA00), u32(0x800AB3D0), u32(0x800AB380), hex(0x800B4D98, 192),
      u32(0x800A3D78), s32(0x8009D510), s32(0x8009D514), hex(0x800C14F0, 8), wait(), bottom(), s32(0x800B4E74) * 4, s32(0x800AB9E8)))
  end
  if f >= LAST then
    out:write("END\n"); out:close()
    if client.exit then client.exit() else client.pause() end
    break
  end
  emu.frameadvance()
end
