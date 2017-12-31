#!/usr/bin/ruby
a,b=gets.split.map &:to_f
if b==0
	p [a,0].max
else
	#x2-ax+b==0
	p (a+Math.sqrt(a*a-4*b))/2
end
