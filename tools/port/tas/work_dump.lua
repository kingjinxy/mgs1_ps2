-- Dumps the Work of every actor whose act is TAS_ACT (hex) at the game loops in TAS_LOOPS (comma separated),
-- TAS_SIZE bytes, as hex words: for diffing an actor against the port's (port printf of the same).
-- Or, with TAS_PTR (hex) instead of TAS_ACT, the Work at *TAS_PTR - TAS_PTROFF (e.g. Snake's: GM_PlayerControl 800AB9F4, 32).
-- Run: TAS_ACT=800C9F50 TAS_SIZE=2428 TAS_LOOPS=38560,38570 tools/port/tas/run_bizhawk.sh tools/port/tas/work_dump.lua
local OUT  = "Z:\\home\\alex\\emu\\tas\\work_dump.log"
local ACT  = tonumber(os.getenv("TAS_ACT") or "0", 16)
local PTR  = tonumber(os.getenv("TAS_PTR") or "0", 16)
local POFF = tonumber(os.getenv("TAS_PTROFF") or "0")
local SIZE = tonumber(os.getenv("TAS_SIZE") or "256")
local LOOPS, LAST, first = {}, 0, math.huge
for v in string.gmatch(os.getenv("TAS_LOOPS") or "", "%d+") do LOOPS[tonumber(v)] = true; LAST = math.max(LAST, tonumber(v)); first = math.min(first, tonumber(v)) end
local RAM  = "MainRAM"
local function a(addr) return addr % 0x200000 end
local function u32(addr) return memory.read_u32_le(a(addr), RAM) end
dofile("Z:\\home\\alex\\Documents\\mgs1_ps2\\tools\\port\\tas\\seek.lua")
local out = io.open(OUT, "w")
emu.limitframerate(false)
out:write("# seek " .. seek(first) .. "\n"); out:flush()
local prev = -1
while true do
  local t = u32(0x800AB330)
  if t ~= prev then
    prev = t
    if t % 500 == 0 then out:write("# " .. t .. "\n"); out:flush() end -- progress, for run_bizhawk.sh's stall check
    if LOOPS[t] and PTR ~= 0 then
      local base, w = u32(PTR) - POFF, {}
      for o = 0, SIZE - 4, 4 do w[#w + 1] = string.format("%08x", u32(base + o)) end
      out:write(t .. " " .. table.concat(w, " ") .. "\n")
    elseif LOOPS[t] then
      for lv = 0, 8 do
        local list = 0x800ACC18 + 0x44 * lv
        local act, i = u32(list + 4), 0
        while act ~= 0 and act ~= list + 0x20 and i < 128 do
          if u32(act + 8) == ACT then
            local w = {}
            for o = 0, SIZE - 4, 4 do w[#w + 1] = string.format("%08x", u32(act + o)) end
            out:write(t .. " " .. table.concat(w, " ") .. "\n")
          end
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
