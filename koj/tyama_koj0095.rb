#!/usr/bin/ruby
n,c=gets.split.map(&:to_i)
h=Hash.new(0)
n.times{
	l,r=gets.split.map(&:to_i)
	x=(l..r).find{|i|
		h[i]<c
	}
	if x
		h[x]+=1
		p x
	else
		p -1
	end
}