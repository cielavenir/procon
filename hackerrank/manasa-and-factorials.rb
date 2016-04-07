#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	p (5..10**18).bsearch{|i|
		r=0
		d=5
		while d<=i
			r+=i/d
			d*=5
		end
		r>=n
	}
}