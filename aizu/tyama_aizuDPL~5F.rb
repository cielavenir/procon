#!/usr/bin/ruby
def comb(n,k)
	return 0 if k<0||n<k
	r=1
	k.times{|i|r=r*(n-i)/(i+1)}
	r
end
a,b=gets.split.map &:to_i
p comb(a-1,a-b)%(10**9+7)
