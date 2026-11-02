-- The PS1's stream and disc state each game loop, for the disc timeline (docs/TAS Testing Plan.md): GV_Time,
-- StrctrlWork's act, Die, state and sub state, fs_stream_bottom's offset, the CD read's bytes left, str_tick_count,
-- str_status, jimctrl.c's state and field_30 (after its loop, the sound counter >> 2 it read). Run: TAS_TO=<loop> tools/port/tas/run_bizhawk.sh tools/port/tas/timeline.lua
local OUT = "Z:\\home\\alex\\emu\\tas\\timeline.log"
local TO  = (os and os.getenv and tonumber(os.getenv("TAS_TO") or "")) or 2000000000
local RAM = "MainRAM"
local WORK = 0x0B82B0
local JIMAKU = 0xb82f0
local function u32(a) return memory.read_u32_le(a, RAM) end
local function s32(a) return memory.read_s32_le(a, RAM) end
local out = io.open(OUT, "w")
emu.limitframerate(false)
local prev, n = -1, 0
while true do
  local t = u32(0x0AB330)
  if t ~= prev then
    prev = t
    local heap = u32(0x0B52A4)
    out:write(string.format("%d %08x %08x %d %d %d %d %d %d %d %d\n", t, u32(WORK + 8), u32(WORK + 12),
      memory.read_s16_le(WORK + 0x20, RAM), memory.read_s16_le(WORK + 0x22, RAM),
      heap == 0 and -1 or u32(0x0B52BC) - heap, s32(0x0B4E74) * 4, s32(0x09F7B4), s32(0x0BF16C), s32(JIMAKU + 0x20), s32(JIMAKU + 0x30)))
    n = n + 1
    if n % 200 == 0 then out:flush() end
    if t > TO then
      out:write("END\n"); out:close()
      client.exit()
      break
    end
  end
  emu.frameadvance()
end
