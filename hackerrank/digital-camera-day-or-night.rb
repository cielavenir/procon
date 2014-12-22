#!/usr/bin/ruby
a=$<.flat_map{|e|e.split.map{|f|f.split(',').map(&:to_i)}}
x=a.count{|e|e.reduce(:+)>=64*3}
puts x*2>a.size ? :day : :night