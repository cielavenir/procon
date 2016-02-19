#!/usr/bin/ruby
def comb(n,k)
	r=1
	k.times{|i|
		r=r*(n-i)/(i+1)
	}
	r
end
n=gets.to_i
p comb(n+4,5)*comb(n+2,3)