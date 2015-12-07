#!/usr/bin/ruby
a=gets.to_i
b=gets.to_i
if a*b<0
	p (a-b).abs*2
else
	p [a.abs,b.abs].max*2
end