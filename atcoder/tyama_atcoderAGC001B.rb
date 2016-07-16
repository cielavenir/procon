#!/usr/bin/ruby
n,x=gets.split.map(&:to_i)
g=n.gcd(x)
r=3*(n/g-1)
p r*g