#!/usr/bin/env lua
local r = 1 << 29
local n = tonumber(io.read("*l"))
for _ in io.read("*l"):gmatch("%d+") do
  local r0 = 0
  local k = tonumber(_)
  while k % 2 < 1 do
    r0 = r0 + 1
    k = k // 2
  end
  if r > r0 then
    r = r0
  end
end
return print(r)
