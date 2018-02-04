#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i)
b=gets.split.map(&:to_i)
c=a.zip(b).reduce(0){|s,(x,y)|s+(x>y ? x-y : 0)}
d=a.zip(b).reduce(0){|s,(x,y)|s+(x<y ? (y-x+1)/2 : 0)}
puts b.reduce(:+)-a.reduce(:+)<[c,d].max ? :No : :Yes
