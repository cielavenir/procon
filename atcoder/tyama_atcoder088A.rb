#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i
puts [:Balanced,:Left,:Right][a+b<=>c+d]
