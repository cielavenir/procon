#!/usr/bin/ruby
s=gets.chomp.bytes.map{|e|e-97}
n=gets.to_i
a=gets.split.map(&:to_i)
p (s.map{|e|a[e]}+[a.max]*n).each.with_index(1).reduce(0){|s,(e,i)|s+e*i}