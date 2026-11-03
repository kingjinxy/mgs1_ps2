-- Dumps the PS1's 2 MB of main RAM at the game loop TAS_LOOP (from the nearest checkpoint, seek.lua) to
-- ~/emu/tas/ram_<loop>.bin, for tools/port/tas/ram_diff.py against the port's (host:tas_ramdump.txt).
-- Run: TAS_LOOP=47498 tools/port/tas/run_bizhawk.sh tools/port/tas/ram_dump.lua
local LOOP = tonumber(os.getenv("TAS_LOOP") or "0")
local OUT  = "Z:\\home\\alex\\emu\\tas\\ram_dump.log"
dofile("Z:\\home\\alex\\Documents\\mgs1_ps2\\tools\\port\\tas\\seek.lua")
local out = io.open(OUT, "w")
emu.limitframerate(false)
out:write("# seek " .. seek(LOOP) .. "\n"); out:flush()
local prev = -1
while true do
  local t = memory.read_u32_le(0x0AB330, "MainRAM")
  if t ~= prev then
    prev = t
    if t % 500 == 0 then out:write("# " .. t .. "\n"); out:flush() end
    if t == LOOP then
      local f = io.open("Z:\\home\\alex\\emu\\tas\\ram_" .. LOOP .. ".bin", "wb")
      for a = 0, 0x1FFFFF, 4096 do
        local b = memory.readbyterange(a, 4096, "MainRAM")
        local s = {}
        for i = 0, 4095 do s[#s + 1] = string.char(b[i] or 0) end
        f:write(table.concat(s))
      end
      f:close()
      out:write("END\n"); out:close()
      if client.exit then client.exit() else client.pause() end
      break
    end
  end
  emu.frameadvance()
end
