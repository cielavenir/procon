#!/usr/bin/ruby
n,q=gets.split.map &:to_i
q.times{
	x,y=gets.split.map &:to_i
	p ((x-1)*n+y+1+(x+y)%2*n*n)/2
}
