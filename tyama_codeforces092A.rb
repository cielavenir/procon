#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
m%=n*(n+1)/2
p 0.step(n).map{|e|m-e*(e+1)/2}.take_while{|e|e>=0}.last