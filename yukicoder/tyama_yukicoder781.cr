#!/usr/bin/env crystal
x,y=gets.not_nil!.split.map &.to_i
r=Math.sqrt(y).to_i
h=[0]*(r*r*4)
(1..r).map{|x|(0..r).map{|y|h[x*x+y*y]+=1}}
p (x..y).map{|i|h[i]}.max*4
