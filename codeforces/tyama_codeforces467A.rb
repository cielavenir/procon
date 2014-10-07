#!/usr/bin/ruby
p gets.to_i.times.count{
	x,y=gets.split.map(&:to_i)
	y-x>1
}