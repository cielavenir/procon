#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i)
n=gets.to_i
a=[n-a,0].max
b=[2*n-b,0].max
c=[3*n-c,0].max
puts [a,b,c]*' '