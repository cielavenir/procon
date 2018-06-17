#!/usr/bin/env lua
local a = io.read("*n")
local b, c = io.read("*n", "*n")
io.read("*l")
local l = io.read("*l")
return print(tostring(a + b + c) .. " " .. l)
