#!/usr/bin/ruby
N=gets.to_i
p (10..10**4).find{|e|
	n=e
	d=1
	r=0
	while n>0
		r+=n%10*d
		n/=10
		d*=e
	end
	r==N
}||-1