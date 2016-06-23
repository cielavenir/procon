#!/usr/bin/ruby
#cf:codeiq2785
x0,y0,r0,x1,y1,r1=`dd`.split.map(&:to_i)
d=Math.hypot(x0-x1,y0-y1)
r0,r1=[r0,r1].minmax
if d>r0+r1
	p 4
elsif d==r0+r1
	p 3
elsif d>r1-r0
	p 2
elsif d==r1-r0
	p 1
else
	p 0
end