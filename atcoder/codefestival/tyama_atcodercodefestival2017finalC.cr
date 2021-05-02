#!/usr/bin/env crystal
a=ARGF.gets_to_end.split.map &.to_i
n=a.shift
a.sort!
b=[0]+n.times.map{|j|a[j]*(-1)**j%24}.to_a
s=24
(n+1).times{|j|(j+1..n).each{|k|s=[s,(b[j]-b[k])%24,(b[k]-b[j])%24].min}}
p s
