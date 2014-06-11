#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
r=0
x=0
gets.split.map(&:to_i).each{|e|
	if x<e
		r+=1
		x=m
	end
	x-=e
}
p r