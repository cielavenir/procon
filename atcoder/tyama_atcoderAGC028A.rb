#!/usr/bin/ruby
n,m=gets.split.map &:to_i
s=gets;t=gets
g=n.gcd m
p g.times.all?{|i|s[n/g*i]==t[m/g*i]} ? n/g*m : -1
