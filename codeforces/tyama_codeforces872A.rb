#!/usr/bin/ruby
gets
a,b=$<.map{|e|e.split}
puts (a&b).empty? ? [a.min,b.min].sort.reduce(:+) : (a&b).min
