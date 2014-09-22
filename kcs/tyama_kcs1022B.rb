#!/usr/bin/ruby
n=gets.to_i
H=gets.to_i
h=H
r=0
a,x=gets.split.map(&:to_i)
b,y=gets.split.map(&:to_i)
n.times{
	if h>=x
		r+=a
		h-=x
	else
		r-=b
		h+=y
		h=H if h>H
	end
}
p r