#!/usr/bin/ruby
n,x,y=$<.read.split.map &:to_i
puts x+y>n+1?:Black: :White
