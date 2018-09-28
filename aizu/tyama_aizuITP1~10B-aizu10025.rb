#!/usr/bin/ruby
include Math
a,b,c=gets.split.map(&:to_f)
c=c*PI/180
p a*b*sin(c)/2,a+b+sqrt(a*a+b*b-2*a*b*cos(c)),b*sin(c)