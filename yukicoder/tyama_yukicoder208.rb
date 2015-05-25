#!/usr/bin/ruby
x,y=gets.split.map &:to_i
a,b=gets.split.map &:to_i
p [x,y].max+(x==y&&a==b&&a<x ? 1 : 0)