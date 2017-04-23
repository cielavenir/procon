#!/usr/bin/ruby
x,y=$<.map &:to_f
f=(x-y).abs>180 ? 180 : 0
p ((x+y)/2+f)%360
