#!/usr/bin/env lua
local t
do
  local _accum_0 = { }
  local _len_0 = 1
  local _list_0 = {
    "dream",
    "dreamer",
    "erase",
    "eraser"
  }
  for _index_0 = 1, #_list_0 do
    local e = _list_0[_index_0]
    _accum_0[_len_0] = e:reverse()
    _len_0 = _len_0 + 1
  end
  t = _accum_0
end
local s = io.read("*l"):reverse()
local c = 1
local l = s:len()
while c <= l do
  local k = nil
  for _index_0 = 1, #t do
    local e = t[_index_0]
    if s:sub(c, c + e:len() - 1) == e then
      k = e
      break
    end
  end
  if k == nil then
    print("NO")
    return
  end
  c = c + k:len()
end
return print("YES")
