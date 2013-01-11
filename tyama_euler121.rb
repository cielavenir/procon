#!/usr/bin/ruby
n=15
r=(n-1)/2
a=[1]+[0]*r
(n+1).times{|i|r.downto(1){|j|a[j]+=i*a[j-1]}}
p (1..n+1).reduce(&:*)/a.reduce(&:+)