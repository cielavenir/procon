#!/usr/bin/ruby
x,y=[1,1]
while (x+1/2)<10**12 do x,y=[3*x+4*y,2*x+3*y] end
p (y+1)/2