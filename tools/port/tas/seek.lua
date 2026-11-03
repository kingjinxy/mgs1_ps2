-- seek(loop): loads the latest checkpoint (checkpoints.lua) at least 2 game loops before `loop`, so a logger
-- starts there instead of at the movie's start; returns the checkpoint's loop, or 0 (none: plays from the start).
-- Use: dofile("Z:\\home\\alex\\Documents\\mgs1_ps2\\tools\\port\\tas\\seek.lua"); seek(FROM)
local DIR = "Z:\\home\\alex\\emu\\tas\\states\\"
function seek(loop)
  local n = math.floor((loop - 2) / 1000) * 1000
  while n > 0 do
    local path = DIR .. "loop_" .. n .. ".State"
    local f = io.open(path, "rb")
    if f then
      f:close()
      savestate.load(path)
      return n
    end
    n = n - 1000
  end
  return 0
end
