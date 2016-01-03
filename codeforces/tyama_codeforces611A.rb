#!/usr/bin/ruby
n,_,a=gets.split
n=n.to_i
if a=='week'
	p n==5||n==6 ? 53 : 52
else
	p [31,29,31,30,31,30,31,31,30,31,30,31].count{|e|e>=n}
end