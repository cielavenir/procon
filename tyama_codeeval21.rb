#!/usr/bin/ruby
while s=gets do p s.chars.reduce(0){|s,e|s+e.to_i} end