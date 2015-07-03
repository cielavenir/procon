#!/usr/bin/ruby
D,M,Y=gets.split.map(&:to_i)
d,m,y=gets.split.map(&:to_i)
if Y>y
	p 10000
elsif Y==y&&M>m
	p 500*(M-m)
elsif Y==y&&M==m&&D>d
	p 15*(D-d)
else
	p 0
end