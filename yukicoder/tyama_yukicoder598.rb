#!/usr/bin/ruby
n,x,a,b=$<.map &:to_i
p [(x+a-1)/a,(2**~-n+~x+b)/b].min
