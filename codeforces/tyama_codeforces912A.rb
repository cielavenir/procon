#!/usr/bin/ruby
a,b,x,y,z=$<.read.split.map &:to_i
a-=2*x
a-=y
b-=y
b-=3*z
p [-a,0].max+[-b,0].max
