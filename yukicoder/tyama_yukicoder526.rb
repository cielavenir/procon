#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a,b=0,1
(n-1).times{a,b=(a+b)%m,a}
p a
