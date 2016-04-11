#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a=[*1..(m+3)/4*4].each_slice(2).each_slice(n).to_a
puts a.shift.zip(*a).flat_map{|(a,b),(c,d)|[c,a,d,b]}.select{|e|e&&e<=m}*' '