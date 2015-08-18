#!/usr/bin/ruby
gets
A=$<.map{|e|e.split.map(&:to_i)}
h=Hash.new(0)
A.each{|e|h[e.each_with_index.map{|x,i|[-x,i]}.min[1]]+=1}
p h.min_by{|k,v|[-v,k]}[0]+1