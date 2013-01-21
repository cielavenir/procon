#!/usr/bin/ruby
require 'prime'
M=28123
a=[];h={}
1.step(M){|i|x=i.prime_division.reduce(1){|s,e|s=s*(e[0]**(e[1]+1)-1)/(e[0]-1)}-i;a<<i if i<x}
a.length.times{|i|a.length.times{|j|h[a[i]+a[j]]=1}}
p 1.step(M).select{|i|!h[i]}.reduce(:+)