#!/usr/bin/ruby
def comb(n,k)
	r=1
	k.times{|i|r=r*(n-i)/(i+1)}
	r
end
a,b=gets.split.map &:to_i
p comb(b,a)%(10**9+7)
