#!/usr/bin/ruby
d,a=$<.map{|l|l.split.map(&:to_i)}
r=0
a.size.times{|i|(i+1).step(a.size-1){|j|r+=2 if (a[i]-a[j]).abs<=d[1]}}
p r