#!/usr/bin/ruby
px,py,vx,vy,a,b,c,d=gets.split.map &:to_f
l=Math.hypot(vx,vy)
puts [b,0,0,-d,-d,0,0].zip([0,-a,-c,-c,c,c,a]).map{|s,t|[px+s/l*vx+t/2/l*vy,py+s/l*vy-t/2/l*vx]*' '}