#!/usr/bin/ruby
px,py=gets.split.map(&:to_f)
cx,cy,r=gets.split.map(&:to_f)
pxd=px-cx
pyd=py-cy
z=Math.sqrt((pxd**2+pyd**2)-r**2)
w=pxd**2+pyd**2
puts [[r*(r*pxd+pyd*z)/w+cx,r*(r*pyd-pxd*z)/w+cy],[r*(r*pxd-pyd*z)/w+cx,r*(r*pyd+pxd*z)/w+cy]].sort.map{|e|e*' '}