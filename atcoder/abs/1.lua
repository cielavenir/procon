#!/usr/bin/env lua
local a, b = io.read("*n", "*n")
return print((function()
  if a * b % 2 > 0 then
    return "Odd"
  else
    return "Even"
  end
end)())
