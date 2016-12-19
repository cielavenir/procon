#!/usr/bin/ruby
x,y,a,b=`dd`.split.map &:to_i
p [x,y].max+(x==y&&a==b&&a<x ?1:0)
