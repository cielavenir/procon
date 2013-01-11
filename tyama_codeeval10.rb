#!/usr/bin/ruby
while s=gets
	a=s.split
	n=a.pop.to_i
	if n>a.length then next end
	puts a[a.length-n]
end