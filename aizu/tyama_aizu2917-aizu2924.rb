#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i
puts a*b%2>0&&(c+d)%2>0 ? :No : :Yes
