#!/usr/bin/ruby
gets
g=Hash.new(0);gets.split.each{|e|g[e.to_i]+=1}
gets
h=Hash.new(0);gets.split.each{|e|h[e.to_i]+=1}
puts h.keys.sort.select{|e|h[e]>g[e]}*' '