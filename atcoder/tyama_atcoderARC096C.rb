#!/usr/bin/ruby
a,b,c,x,y=gets.split.map &:to_i;c*=2
x>y&&(a,b=b,a;x,y=y,x)
b>c&&b=c
p [a*x+b*y,c*x+b*y-=x].min
