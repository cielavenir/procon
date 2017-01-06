#!/usr/bin/ruby
a=gets.split.map(&:to_i)
s=a.reduce(:+)
puts '%d %d'%[s-a.max,s-a.min]
