-- Plays the movie once and saves a BizHawk state every 1,000 game loops (GV_Time) into ~/emu/tas/states/,
-- loop_<N>.State, for the loggers to start near their loops (seek.lua) instead of replaying from the start.
-- Resumes after the last state already there. The PS1 side never changes, so this runs once (again only if the movie or BizHawk's settings change).
-- Run: tools/port/tas/run_bizhawk.sh tools/port/tas/checkpoints.lua
local OUT   = "Z:\\home\\alex\\emu\\tas\\checkpoints.log"
local DIR   = "Z:\\home\\alex\\emu\\tas\\states\\"
local EVERY = 1000
local function u32(addr) return memory.read_u32_le(addr % 0x200000, "MainRAM") end
dofile("Z:\\home\\alex\\Documents\\mgs1_ps2\\tools\\port\\tas\\seek.lua")
local out = io.open(OUT, "a")
emu.limitframerate(false)
local prev, saved = -1, seek(1000000) -- resumes after the last state saved
while true do
  local t = u32(0x800AB330)
  if t ~= prev then
    if t % 500 == 0 then out:write("# " .. t .. "\n"); out:flush() end -- progress, for run_bizhawk.sh's stall check
    if t % EVERY == 0 and t > saved then
      savestate.save(DIR .. "loop_" .. t .. ".State")
      out:write("saved " .. t .. " frame " .. emu.framecount() .. "\n"); out:flush()
      saved = t
    end
    prev = t
  end
  if movie.mode() == "FINISHED" or emu.framecount() >= movie.length() then
    out:write("END\n"); out:close()
    if client.exit then client.exit() else client.pause() end
    break
  end
  emu.frameadvance()
end
