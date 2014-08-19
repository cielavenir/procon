#!/usr/bin/ruby
n,v=gets.split.map(&:to_i)
a=1.step(n).select{gets.split.map(&:to_i)[1..-1].any?{|e|e<v}}
p a.size
puts a*' '