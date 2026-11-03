-- Lists every actor (level, act address, source filename) at the game loops in TAS_LOOPS (comma separated), from
-- the nearest checkpoint (seek.lua): for comparing the PS1's actors with the port's at a desync.
-- Run: TAS_LOOPS=47496,47497 tools/port/tas/run_bizhawk.sh tools/port/tas/actor_list.lua
local OUT  = "Z:\\home\\alex\\emu\\tas\\actor_list.log"
local LOOPS, LAST, first = {}, 0, math.huge
for v in string.gmatch(os.getenv("TAS_LOOPS") or "", "%d+") do
  LOOPS[tonumber(v)] = true; LAST = math.max(LAST, tonumber(v)); first = math.min(first, tonumber(v))
end
local RAM = "MainRAM"
local function a(addr) return addr % 0x200000 end
local function u32(addr) return memory.read_u32_le(a(addr), RAM) end
local function str(addr)
  local s = ""
  for i = 0, 31 do local c = memory.readbyte(a(addr + i), RAM); if c == 0 then break end; s = s .. string.char(c) end
  return s
end
dofile("Z:\\home\\alex\\Documents\\mgs1_ps2\\tools\\port\\tas\\seek.lua")
local out = io.open(OUT, "w")
emu.limitframerate(false)
out:write("# seek " .. seek(first) .. "\n"); out:flush()
local prev = -1
while true do
  local t = u32(0x800AB330)
  if t ~= prev then
    prev = t
    if t % 500 == 0 then out:write("# " .. t .. "\n"); out:flush() end
    if LOOPS[t] then
      for lv = 0, 8 do
        local list = 0x800ACC18 + 0x44 * lv
        local act, i = u32(list + 4), 0
        while act ~= 0 and act ~= list + 0x20 and i < 256 do
          out:write(string.format("%d %d %08x %s\n", t, lv, u32(act + 8), str(u32(act + 20))))
          act, i = u32(act + 4), i + 1
        end
      end
    end
    if t > LAST then
      out:write("END\n"); out:close()
      if client.exit then client.exit() else client.pause() end
      break
    end
  end
  emu.frameadvance()
end
