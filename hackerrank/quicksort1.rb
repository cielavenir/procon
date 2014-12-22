#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i)
x=a.shift
b=a.partition{|e|e<x}
puts (b[0]+[x]+b[1])*' '