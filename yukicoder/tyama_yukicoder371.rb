#!/usr/bin/ruby
require 'prime'
l,h=gets.split.map(&:to_i)
r=0;v=nil
j=Math.sqrt(h).to_i+1
while !v||j>=v
	j-=1
	next if h/j*j<l || !j.prime?
	i=h/j
	while i>=l&&i*j>=l
		t=(i*j).prime_division[0][0]
		if !v || v<t || (v==t&&r<i*j)
			v=t
			r=i*j
		end
		i-=1
	end
end
p r