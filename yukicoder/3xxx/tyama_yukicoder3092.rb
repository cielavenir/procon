#!/usr/bin/ruby
n,m=gets.split.map &:to_i
puts m.times.any?{
	x,y,a,b=gets.split.map &:to_i
	a<0 || b<0
} ? -1 : [1]*n*' '
