#!/usr/bin/env lua
local a = io.read("*n")
local b = io.read("*n")
local c = io.read("*n")
local x = io.read("*n")
local r = 0
for i = 0, 500 do
  for j = 0, (x - 500 * i) // 100 do
    local k = x - 500 * i - 100 * j
    if k % 50 == 0 and c >= k // 50 and a >= i and b >= j then
      r = r + 1
    end
  end
end
return print(r)
