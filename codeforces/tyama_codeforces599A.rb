#!/usr/bin/ruby
a=gets.split.map(&:to_i)
s=a.reduce(:+)
p [(s-a.max)*2,s].min