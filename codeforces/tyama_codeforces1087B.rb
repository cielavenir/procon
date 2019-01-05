#!/usr/bin/ruby
n,k=gets.split.map &:to_i
d=k-1
d-=1 while n%d>0
p n/d*k+d
