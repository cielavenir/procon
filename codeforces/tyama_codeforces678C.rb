#!/usr/bin/ruby
n,a,b,x,y=gets.split.map(&:to_i)
c=n/a.lcm(b)
a=n/a
b=n/b
p a*x+b*y-c*[x,y].min