#!/usr/bin/ruby
x,y,r,x0,y0,x1,y1=$<.read.split.map(&:to_i)
puts x0<=x-r&&x+r<=x1 && y0<=y-r&&y+r<=y1 ? :NO : :YES
puts [x0,x1].product([y0,y1]).all?{|xx,yy|(x-xx)**2+(y-yy)**2<=r*r} ? :NO : :YES