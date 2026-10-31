-- Logs s03d's guards (zako.c's Work, act s03d_800CCC54) each game loop from GV_Time TAS_FROM to TAS_TO, for comparing
-- with the port's (the same fields): GV_Time, the actor's place in its list, mov xyz, ACC, AD0, AD8, B04, B64, B90.
-- Run: tools/port/tas/run_bizhawk.sh tools/port/tas/zako_log.lua (TAS_FROM/TAS_TO in the environment).
local OUT  = "Z:\\home\\alex\\emu\\tas\\zako_log.log"
local FROM = (os and os.getenv and tonumber(os.getenv("TAS_FROM") or "")) or 12650
local TO   = (os and os.getenv and tonumber(os.getenv("TAS_TO") or "")) or 12760
local RAM  = "MainRAM"
local function a(addr) return addr % 0x200000 end
local function u32(addr) return memory.read_u32_le(a(addr), RAM) end
local function s32(addr) local v = u32(addr); return v >= 0x80000000 and v - 0x100000000 or v end
local function s16(addr) local v = memory.read_u16_le(a(addr), RAM); return v >= 0x8000 and v - 0x10000 or v end
local LIST = 0x800ACC18 + 4 * 0x44 -- ActorList[4] (GV_ACT start, end; 0x44 a level)
local out = io.open(OUT, "w")
emu.limitframerate(false)
local prev = -1
while true do
  local t = u32(0x800AB330)
  if t ~= prev then
    prev = t
    if t % 500 == 0 then out:write("# " .. t .. "\n"); out:flush() end -- progress, for run_bizhawk.sh's stall check
    if t >= FROM then
      local act, i = u32(LIST + 4), 0
      while act ~= 0 and act ~= LIST + 0x20 and i < 64 do
        if u32(act + 8) == 0x800CCC54 then
          out:write(string.format("%d %d %d %d %d %d %d %08x %d %d %d", t, i, s16(act + 0x20), s16(act + 0x22),
            s16(act + 0x24), s16(act + 0xACC), s32(act + 0xAD0), u32(act + 0xAD8), s32(act + 0xB04), s32(act + 0xB64),
            s32(act + 0xB90)) .. string.format(" ac %d %d h %d", s16(act + 0xAA), s16(act + 0xAC), s16(act + 0xB4)) .. string.format(" lv %d %d hz %d gr %d st %d %d %d\n", s16(act + 0x20 + 120),
            s16(act + 0x20 + 122), s16(act + 0x20 + 52), memory.readbyte(a(act + 0x20 + 87), RAM), s16(act + 0x20 + 68),
            s16(act + 0x20 + 70), s16(act + 0x20 + 72)))
        end
        act, i = u32(act + 4), i + 1
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
