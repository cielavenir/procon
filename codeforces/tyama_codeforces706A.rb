#!/usr/bin/ruby
a,b=gets.split.map(&:to_f)
p gets.to_i.times.map{
x,y,z=gets.split.map(&:to_f)
	Math.hypot(a-x,b-y)/z
}.min