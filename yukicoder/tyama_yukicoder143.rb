#!/usr/bin/ruby
m,n=gets.split.map(&:to_i)
g=m.gcd(n)
m/=g
n/=g
r=0
while n>1
	if m<n
		r+=1
		m,n=n,m
	else
		r+=m/n
		m-=m/n*n
	end
end
p r+m-1