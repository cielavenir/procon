#!/usr/bin/ruby
M=10**9+7
a=[0,1,0,1]
b=[0,0,1,1]
c=[0,0,0,1]
n=gets.to_i
(4..n).each{|i|
	a[i]=(b[i-1]+c[i-1])%M
	b[i]=(a[i-2]+c[i-2])%M
	c[i]=(a[i-3]+b[i-3])%M
}
p (a[n]+b[n]+c[n])%M
