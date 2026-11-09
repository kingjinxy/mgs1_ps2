-- Logs TAS_SIZE bytes at TAS_ADDR (hex) at the game loops in TAS_LOOPS, from the nearest checkpoint.

-- Run: TAS_ADDR=800B933C TAS_SIZE=64 TAS_LOOPS=137804,137805 tools/port/tas/run_bizhawk.sh tools/port/tas/mem_log.lua
local OUT  = "Z:\\home\\alex\\emu\\tas\\mem_log.log"
local LOOPS, LAST, first = {}, 0, math.huge
for v in string.gmatch(os.getenv("TAS_LOOPS") or "", "%d+") do
  LOOPS[tonumber(v)] = true; LAST = math.max(LAST, tonumber(v)); first = math.min(first, tonumber(v))
end
local RAM = "MainRAM"
local function a(addr) return addr % 0x200000 end
local function u32(addr) return memory.read_u32_le(a(addr), RAM) end
local function hex(addr, n)
  local s = ""
  for i = 0, n - 1 do s = s .. string.format("%02x", memory.readbyte(a(addr + i), RAM)) end
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
    if LOOPS[t] then
      out:write(string.format("%d %s\n", t, hex(tonumber(os.getenv("TAS_ADDR"), 16), tonumber(os.getenv("TAS_SIZE") or "64"))))
      out:flush()
    end
    if t > LAST then
      out:write("END\n"); out:close()
      if client.exit then client.exit() else client.pause() end
      break
    end
  end
  emu.frameadvance()
end
