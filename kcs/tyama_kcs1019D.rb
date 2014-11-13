#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i)
puts a*c>=b*4950 ? :YES : :NO