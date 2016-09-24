#!/usr/bin/ruby
#complexity: O(sqrt(a)+log(b))
require 'prime'
a,b0=gets.split.map(&:to_i)
p a.prime_division.map{|n,p|
	b=b0
	r=0
	while b>0
		r+=b/n
		b/=n
	end
	r/p
}.min
