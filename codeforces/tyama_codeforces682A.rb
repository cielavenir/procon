#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
p (1..n).reduce(0){|s,i|s+(m+i%5)/5}