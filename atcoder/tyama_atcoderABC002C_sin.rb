#!/usr/bin/ruby
x1,y1,x2,y2,x3,y3=gets.split.map(&:to_f)
a=Math.hypot(x1-x2,y1-y2)
b=Math.hypot(x1-x3,y1-y3)
c=Math.hypot(x2-x3,y2-y3)
cos=(a*a+b*b-c*c)/(2*a*b)
sin=Math.sqrt(1-cos*cos)
p a*b*sin/2