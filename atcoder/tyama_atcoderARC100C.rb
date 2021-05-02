#!/usr/bin/ruby
n=gets.to_i;a=gets.split.map.with_index(1){|e,i|e.to_i-i}.sort
m=a[n/2];r=0
a.each{|e|r+=(e-m).abs}
p r
