#!/usr/bin/env lua
local n = io.read("*n")
local t = 0
local x = 0
local y = 0
for i = 1, n do
  local t0, x0, y0 = io.read("*n", "*n", "*n")
  local dt = t0 - t
  local dx = x0 - x
  local dy = y0 - y
  if dx + dy > dt or (dt - dx - dy) % 2 > 0 then
    print("No")
    return
  end
  t = t0
  x = x0
  y = y0
end
return print("Yes")
