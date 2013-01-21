#!/usr/bin/ruby
require 'prime'
h={}
2.step(9999){|i|h[i]=i.prime_division.reduce(1){|s,e|s=s*(e[0]**(e[1]+1)-1)/(e[0]-1)}-i}
p 2.step(9999).select{|i|x=h[i];x!=i&&h[x]==i}.reduce(:+)