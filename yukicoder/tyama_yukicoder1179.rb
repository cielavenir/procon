#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
(a=-a;b=-b;c=-c) if a<0
d=b*b-4*a*c
if d<0
	puts :imaginary
elsif d==0
	p -b/a/2
else
	puts [(-b-Math.sqrt(d))/a/2, (-b+Math.sqrt(d))/a/2]*' '
end
