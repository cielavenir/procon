#!/usr/bin/ruby
def f(m)
	r=1
	r*=2 while r*2<=m
	r
end
N,B,P=gets.split.map(&:to_i)
r=0
n=N
while n>1
	k=f(n)
	r+=k*B+k/2
	n=n-k/2
end
puts '%d %d'%[r,N*P]