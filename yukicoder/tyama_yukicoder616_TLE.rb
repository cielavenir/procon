#!/usr/bin/env ruby
M=10**9+7
n,k=gets.split.map &:to_i
a=[1]+[0]*-~k
n.times{|i|
	b=[0]*(k+2)
	(0..k).each{|j|
		b[j]=(b[j]+a[j])%M
		b[j+[i,k-j].min+1]=(b[j+[i,k-j].min+1]-a[j])%M
	}
	(0..k).each{|j|b[j+1]=(b[j+1]+b[j])%M}
	a=b
}
p a.reduce(:+)%M
