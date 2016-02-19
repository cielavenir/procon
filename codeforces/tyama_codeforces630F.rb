#!/usr/bin/ruby
def comb(n,k)
	r=1
	k.times{|i|
		r=r*(n-i)/(i+1)
	}
	r
end
n=gets.to_i
p comb(n,5)+comb(n,6)+comb(n,7)