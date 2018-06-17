#!/usr/bin/env lua
local n = io.read("*n")
local arr
do
  local _accum_0 = { }
  local _len_0 = 1
  for i = 1, n do
    _accum_0[_len_0] = io.read("*n")
    _len_0 = _len_0 + 1
  end
  arr = _accum_0
end
table.sort(arr)
local r = 1
for i = 2, n do
  if arr[i - 1] ~= arr[i] then
    r = r + 1
  end
end
return print(r)
