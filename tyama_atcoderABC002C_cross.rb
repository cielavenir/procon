#!/usr/bin/ruby
x1,y1,x2,y2,x3,y3=gets.split.map(&:to_f)
vx1=x2-x1;vx2=x3-x1
vy1=y2-y1;vy2=y3-y1
p (vx1*vy2-vx2*vy1).abs/2.0