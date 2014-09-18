#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
raise if m>2
p (2**(n-1)-1)%1000000007