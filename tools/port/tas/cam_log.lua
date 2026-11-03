-- Logs s08a's gun cameras (guncame.c's Work, act 0x800CAA00) each game loop from GV_Time TAS_FROM to TAS_TO:
-- GV_Time, the Work's address, field_344, field_34C, turn.vy, field_330.vy, field_36C.
-- Run: TAS_FROM=.. TAS_TO=.. tools/port/tas/run_bizhawk.sh tools/port/tas/cam_log.lua
local OUT  = "Z:\\home\\alex\\emu\\tas\\cam_log.log"
local FROM = (os and os.getenv and tonumber(os.getenv("TAS_FROM") or "")) or 35080
local TO   = (os and os.getenv and tonumber(os.getenv("TAS_TO") or "")) or 35095
local RAM  = "MainRAM"
local function a(addr) return addr % 0x200000 end
local function u32(addr) return memory.read_u32_le(a(addr), RAM) end
local function s16(addr) local v = memory.read_u16_le(a(addr), RAM); return v >= 0x8000 and v - 0x10000 or v end
local function s32(addr) local v = u32(addr); return v >= 0x80000000 and v - 0x100000000 or v end
local out = io.open(OUT, "w")
emu.limitframerate(false)
local prev = -1
while true do
  local t = u32(0x800AB330)
  if t ~= prev then
    prev = t
    if t % 500 == 0 then out:write("# " .. t .. "\n"); out:flush() end -- progress, for run_bizhawk.sh's stall check
    if t >= FROM then
      for lv = 0, 8 do
        local list = 0x800ACC18 + 0x44 * lv
        local act, i = u32(list + 4), 0
        while act ~= 0 and act ~= list + 0x20 and i < 128 do
          if u32(act + 8) == 0x800CAA00 then
            out:write(string.format("%d %06x s%d c%d ty%d cy%d lim%d\n", t, act % 0x1000000, s32(act + 0x344),
              s32(act + 0x34C), s16(act + 0x6E), s16(act + 0x332), s32(act + 0x36C)))
          end
          act, i = u32(act + 4), i + 1
        end
      end
    end
    if t > TO then
      out:write("END\n"); out:close()
      if client.exit then client.exit() else client.pause() end
      break
    end
  end
  emu.frameadvance()
end
