#!/usr/bin/env lua
local n, a, b = io.read("*n", "*n", "*n")
local r = 0
for i = 1, n do
  local s = 0
  local j = i
  while j > 0 do
    s = s + (j % 10)
    j = j // 10
  end
  if a <= s and s <= b then
    r = r + i
  end
end
return print(r)
