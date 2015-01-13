#!/usr/bin/ruby
gets.to_i.times{
	b,w=gets.split.map(&:to_i)
	x,y,z=gets.split.map(&:to_i)
	p w*[y,x+z].min+b*[x,y+z].min
}