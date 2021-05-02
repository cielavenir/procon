#!/usr/bin/ruby
#b=gets.to_i.lcm gets.to_i;p (gets.to_i+b-1)/b*b
#a,b,n=$<.map &:to_i;b=b.lcm a;p (n+b-1)/b*b
a,b,n=$<.map &:to_i;p (n-1+b=b.lcm(a))/b*b