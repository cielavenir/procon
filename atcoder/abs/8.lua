#!/usr/bin/env lua
local n, y = io.read("*n", "*n")
for i = 0, n do
  for j = 0, n - i do
    local k = n - i - j
    if i * 1000 + j * 5000 + k * 10000 == y then
      print(tostring(k) .. " " .. tostring(j) .. " " .. tostring(i))
      return
    end
  end
end
return print("-1 -1 -1")
