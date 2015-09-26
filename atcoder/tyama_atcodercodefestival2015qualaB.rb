#!/usr/bin/ruby
N=gets.to_i
A=gets.split.map(&:to_i)
r=0
N.times{|i|r=2*r+A[i]}
p r