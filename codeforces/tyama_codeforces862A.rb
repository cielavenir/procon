#!/usr/bin/ruby
n,x,*a=$<.read.split.map &:to_i
b=[*0...x]-a
p b.size+(a.include?(x)?1:0)
