#!/usr/bin/ruby
x,*a=$<.read.split
puts a.any?{|e|x[0]==e[0] || x[1]==e[1]} ? :YES : :NO
