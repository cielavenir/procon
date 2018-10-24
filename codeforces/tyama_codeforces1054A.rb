#!/usr/bin/ruby
x,y,z,a,b,c=gets.split.map &:to_i
d=(x-y).abs
puts d*a<((x-z).abs+d)*b+3*c ? :No : :Yes
