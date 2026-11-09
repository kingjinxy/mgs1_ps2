-- Logs GM_PlayerStatus, GV_PadData[0]'s first 8 bytes and every trap bind (24 bytes each) at the game loops in
-- TAS_LOOPS (comma separated), from the nearest checkpoint: for a trap that fires on one side only.
-- Run: TAS_LOOPS=105449,105450 tools/port/tas/run_bizhawk.sh tools/port/tas/bind_log.lua
local OUT  = "Z:\\home\\alex\\emu\\tas\\bind_log.log"
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
      out:write(string.format("%d ps=%08x pad=%s n=%d\n", t, u32(0x800ABA50), hex(0x800B05C0, 8), u32(0x800AB9B8)))
      local bind = u32(0x800AB9BC)
      for i = 0, math.min(u32(0x800AB9B8), 128) - 1 do out:write(string.format("  b%d %s\n", i, hex(bind + 24 * i, 24))) end
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
