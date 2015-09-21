#!/usr/bin/ruby
N,B,c=gets.split.map &:to_i
A=gets.split.map(&:to_i).reverse
r=0
A.each{|e|d=[B,c].min;r+=e*d;c-=d}
p r