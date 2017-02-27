#!/usr/bin/ruby
n=gets.to_i
m=$<.map{|e|e.chomp.bytes}
s=m.transpose.map{|e|e.count 35}
p s.count(0)<n ?n.times.map{|i|(s[i]>0?0:1)+m[i].count(46)}.min+n-s.count(n):-1
