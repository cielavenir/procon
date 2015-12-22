#!/usr/bin/ruby
x1,y1,x2,y2,d=gets.split.map(&:to_i)
x1,x2=-x2,-x1 if x2<0
y1,y2=-y2,-y1 if y2<0
x1,x2,d=0,x2-x1,d-x1 if x1>0
y1,y2,d=0,y2-y1,d-y1 if y1>0
(p 0;exit)if d<0
r=[d,x2].min+[d,-x1].min+[d,y2].min+[d,-y1].min+1
[-x1,x2].product([-y1,y2]){|x,y|
d0=[d-2,x+y-2].min
r+=(d0+1)*(d0+2)/2
r-=(d0-x+1)*(d0-x+2)/2 if x-1<d0
r-=(d0-y+1)*(d0-y+2)/2 if y-1<d0
}
p r