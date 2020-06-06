#!/usr/bin/ruby
n,m,q=gets.split.map &:to_i
c=Hash.new{|h,k|h[k]=[]}
s=[n]*m
q.times{
	z,n,m=gets.split.map &:to_i
	if z==2
		c[n-1]<<m-1
		s[m-1]-=1
	elsif z==1
		p c[n-1].map{|e|s[e]}.reduce 0,:+
	end
}
