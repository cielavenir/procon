#!/usr/bin/ruby
while s=gets
	a=s.split
	n=a.pop.to_i
	if n>a.size then next end
	puts a[a.size-n]
end