#!/usr/bin/ruby
gets.to_i.times{
	t=gets.to_i*2
	#solve n*n+n-t=0 <=> n=(-1+sqrt(1+4t))/2
	n=(-1+Math.sqrt(1+4*t))/2
	if n.to_i==n
		p n.to_i
	else
		p -1
	end
}