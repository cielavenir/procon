#!/usr/bin/ruby
n=gets.to_i
if n==1
	p -1
else
	a=gets.split.map(&:to_i)[-2..-1]
	puts a==[1,0]||a[1]<a[2] ? :UP : :DOWN
end
