#!/usr/bin/env lua
local l = io.read("*l")
local r = 0
for _ in l:gmatch("1") do
  r = r + 1
end
return print(r)
