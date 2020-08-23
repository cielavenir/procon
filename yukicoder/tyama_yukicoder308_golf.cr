#!/usr/bin/env crystal
require "big"
h={4=>3,6=>5,12=>11,14=>13,18=>8,20=>19,21=>19,24=>23,25=>23}
n=BigInt.new(gets.not_nil!)
p n<26 ? h.has_key?(n) ? h[n] : 7 : n%8+`factor #{n-8}`.count(' ')==2 ? 14 : 8
