#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
r=0
x=0
while a>0
	r+=a
	x+=a
	a=x/b
	x%=b
end
p r