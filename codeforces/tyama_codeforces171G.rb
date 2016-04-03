#!/usr/bin/ruby
x,y,z=gets.split.map(&:to_i)
(z-1).times{x,y=y,x+y}
p y