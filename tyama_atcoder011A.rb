#!/usr/bin/ruby
m,n,a=gets.split.map(&:to_i)
s=a
b=0
while a>0
	b+=a
	s+=a=b/m*n
	b%=m
end
p s