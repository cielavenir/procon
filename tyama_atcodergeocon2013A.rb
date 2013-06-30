#!/usr/bin/ruby
Z=3
a=$<.each_with_index.map{|e,i|[e.to_i,i+1]}.sort.map{|e|e[1]}
puts a.size/Z
puts a.each_slice(Z).map{|e|e*' '}