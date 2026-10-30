-- Logs the stage every 600 frames while the movie plays (sync check).
local out = io.open("Z:\\home\\alex\\emu\\tas\\synccheck.log", "w")
local function rd(a) return memory.read_u32_le(a % 0x200000, "MainRAM") end
local function str(p)
  if p < 0x80000000 or p >= 0x80200000 then return "?" end
  local s = ""
  for i = 0, 15 do local c = memory.readbyte((p + i) % 0x200000, "MainRAM"); if c == 0 then break end; s = s .. string.char(c) end
  return s
end
emu.limitframerate(false)
while true do
  local f = emu.framecount()
  if f % 600 == 0 then
    out:write(string.format("%d time=%d stage=%s status=%08x\n", f, rd(0x800AB330), str(0x800AB3C4), rd(0x800AB3CC)))
    out:flush()
  end
  if f >= 313202 then out:write("END\n"); out:close(); if client.exit then client.exit() else client.pause() end; break end
  emu.frameadvance()
end
