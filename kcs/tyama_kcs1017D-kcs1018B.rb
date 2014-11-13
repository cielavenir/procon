#!/usr/bin/ruby
m,n,_a=gets.split.map(&:to_i)
a=_a
s=a
b=0
while a>0
	b+=a
	s+=a=b/m*n
	b%=m
end
p s-_a