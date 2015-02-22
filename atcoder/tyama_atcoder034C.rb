#!/usr/bin/ruby
require'prime'
h=Hash.new(0)
a,b=gets.split.map(&:to_i)
(b+1).upto(a){|i|i.prime_division.each{|n,p|h[n]+=p}}
p h.each_value.reduce(1){|s,e|s*=(e+1)}%1000000007