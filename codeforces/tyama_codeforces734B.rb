#!/usr/bin/ruby
x,y,z,w=gets.split.map &:to_i
c=[x,[z,w].min].min
r=256*c
x-=c
c=[x,y].min
r+=32*c
p r
