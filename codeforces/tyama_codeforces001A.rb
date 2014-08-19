#!/usr/bin/ruby
r=gets.split.map(&:to_i)
a=r[2]
n=r[0]+a-1
m=r[1]+a-1
puts (n/a)*(m/a)