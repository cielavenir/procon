#!/usr/bin/ruby
ma=Float::INFINITY
mi=-ma
s=0
gets.to_i.times{
	c,d=gets.split.map &:to_i
	if d==1
		mi=[mi,1900-s].max
	else
		ma=[ma,1899-s].min
	end
	s+=c
}
puts ma==Float::INFINITY ? :Infinity : ma>=mi ? ma+s : :Impossible
