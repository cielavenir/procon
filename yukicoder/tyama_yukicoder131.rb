#!/usr/bin/ruby
x,y,d=gets.split.map &:to_i
p [0,1+[x,y,d,x+y-d].min].max