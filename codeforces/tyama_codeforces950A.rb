#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
r=[a,b].min
a-=r
b-=r
a+=b
s=[a,c].min
a-=s
c-=s
p r*2+s*2+c/2*2
