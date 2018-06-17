#!/usr/bin/env lua
local n = io.read("*n")
io.read("*l")
local arr
do
  local _accum_0 = { }
  local _len_0 = 1
  for e in io.read("*l"):gmatch("%d+") do
    _accum_0[_len_0] = tonumber(e)
    _len_0 = _len_0 + 1
  end
  arr = _accum_0
end
table.sort(arr, function(a, b)
  return a > b
end)
local r = 0
local t = 1
for _index_0 = 1, #arr do
  local e = arr[_index_0]
  r = r + (t * e)
  t = -t
end
return print(r)
