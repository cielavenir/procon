#!/usr/bin/ruby
require 'prime'
h={};2.step(36){|i|h[i]=i.prime_division}
while(l=gets.chomp)!="0 0"
	l=l.split
	n=l[0].to_i;m=l[1].to_i(n)
	p h[n].map{|a,b|
		z=m;r=0
		while z>0 do r+=(z/=a) end
		r/=b
	}.min
end