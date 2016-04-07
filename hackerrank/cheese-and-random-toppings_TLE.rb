#!/usr/bin/ruby
def comb(n,r)
	r=n-r if r*2>n
	x=1
	r.times{|i|
		x=x*(n-i)/(i+1)
	}
	x
end
gets.to_i.times{
	n,r,m=gets.split.map(&:to_i)
	p comb(n,r)%m
}