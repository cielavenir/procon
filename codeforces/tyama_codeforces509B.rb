#!/usr/bin/env ruby
n,k=gets.split.map(&:to_i)
a=gets.split.map(&:to_i)
b=a.map{|e|
	h=Hash.new(0)
	z=e.times.map{|i|
		n=i%k+1
		h[n]+=1
		n
	}
	[z,h]
}
if b.combination(2).all?{|x,y|
	(1..k).all?{|e|(x[1][e]-y[1][e]).abs<=1}
}
	puts :YES
	puts b.map{|e|e[0]*' '}
else
	puts :NO
end