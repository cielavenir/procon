#!/usr/bin/ruby
M=10**6
n,k=gets.split.map &:to_i
r=[0]*M
n.times{
	a,b=gets.split.map &:to_i
	r[a]+=b
}
p (0..M).find{|i|0>=k-=r[i]}
