#!/usr/bin/ruby
r,c=gets.split.map(&:to_i)
x,y=gets.split.map(&:to_i)
d,l=gets.split.map(&:to_i)
p (r-x+1)*(c-y+1)*(1..d+l).reduce(:*)/((1..d).reduce(:*)||1)/((1..l).reduce(:*)||1)%1000000007