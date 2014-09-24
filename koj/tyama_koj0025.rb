#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i)
puts a*a+b*b==c*c ? :Yes : :No