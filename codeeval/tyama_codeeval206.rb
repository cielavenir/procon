#!/usr/bin/ruby
def comb(n,k)
	k=n-k if k>n/2
	r=1
	k.times{|i|
		r=r*(n-i)/(i+1)
	}
	r
end
$<.each{|_|
	n=_.to_i/2
	p n.times.reduce(0){|s,k|s + (-1)**k * comb(2*n,k) * comb(11*n-1-10*k,2*n-1)}
}