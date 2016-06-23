#!/usr/bin/ruby
cx1,cy1,r1=gets.split.map(&:to_f)
cx2,cy2,r2=gets.split.map(&:to_f)
cxd=cx2-cx1
cyd=cy2-cy1
a=(cxd**2+cyd**2+r1**2-r2**2)/2
z=Math.sqrt((cxd**2+cyd**2)*r1**2-a**2)
w=cxd**2+cyd**2
puts [[(a*cxd+cyd*z)/w+cx1,(a*cyd-cxd*z)/w+cy1],[(a*cxd-cyd*z)/w+cx1,(a*cyd+cxd*z)/w+cy1]].sort*' '