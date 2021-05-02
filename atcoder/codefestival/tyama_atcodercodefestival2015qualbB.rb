#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
h=Hash.new(0)
gets.split.each{|e|h[e.to_i]+=1}
a=h.max_by(&:last)
puts a[1]*2>N ? a[0] : '?'