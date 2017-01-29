#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	m=(2*n).times.map{gets.split.map(&:to_i)}
	r=0
	n.times{|y|n.times{|x|r+=[m[y][x],m[y][2*n-x-1],m[2*n-y-1][x],m[2*n-y-1][2*n-x-1]].max}}
	p r
}
