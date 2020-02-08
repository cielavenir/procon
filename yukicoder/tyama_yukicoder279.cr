#!/usr/bin/env crystal
h=Hash(Char,Int32).new(0)
gets.not_nil!.each_char{|c|h[c]+=1}
p [h['t'],h['r'],h['e'] // 2].min
