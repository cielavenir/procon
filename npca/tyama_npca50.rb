#!/usr/bin/ruby
a=['1'];1.step(12){a<<a.last.chars.group_by{|e|e}.map{|k,v|k.to_s+v.size.to_s}.sort.reduce(:+)}
puts a[[gets.to_i-1,12].min]