#!/usr/bin/ruby
a,b,x,y,c,d=$<.read.split.map(&:to_i)
z=[c-b,0].max
p a-z+[x+z,d].min