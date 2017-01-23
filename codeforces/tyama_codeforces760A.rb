#!/usr/bin/ruby
M=[0,31,28,31,30,31,30,31,31,30,31,30,31]
m,d=gets.split.map(&:to_i)
p (d+M[m]-1+6)/7
