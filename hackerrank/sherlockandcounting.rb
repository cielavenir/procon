#!/usr/bin/ruby
gets.to_i.times{
	n,k=gets.split.map(&:to_i)
	#i2 - ni + nk >= 0
	d=n*n-4*n*k
	if d<0
		p n-1
	else
		x=(n-Math.sqrt(d))/2
		p x.to_i*2 - (d==0 ? 1 : 0)
	end
}