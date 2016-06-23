#!/usr/bin/ruby
R=[]
cx1,cy1,r1=gets.split.map(&:to_f)
cx2,cy2,r2=gets.split.map(&:to_f)
cxd=cx2-cx1
cyd=cy2-cy1
w=cxd**2+cyd**2
d_outer=cxd**2+cyd**2-(r1+r2)**2
if d_outer>-1e-9
	d_outer=0 if d_outer.abs<1e-9
	R<<[r1*(cxd*(r1+r2)+cyd*Math.sqrt(d_outer))/w+cx1,r1*(cyd*(r1+r2)-cxd*Math.sqrt(d_outer))/w+cy1]
	R<<[r1*(cxd*(r1+r2)-cyd*Math.sqrt(d_outer))/w+cx1,r1*(cyd*(r1+r2)+cxd*Math.sqrt(d_outer))/w+cy1]
end
d_inner=cxd**2+cyd**2-(r1-r2)**2
if d_inner>-1e-9
	d_inner=0 if d_inner.abs<1e-9
	R<<[r1*(cxd*(r1-r2)+cyd*Math.sqrt(d_inner))/w+cx1,r1*(cyd*(r1-r2)-cxd*Math.sqrt(d_inner))/w+cy1]
	R<<[r1*(cxd*(r1-r2)-cyd*Math.sqrt(d_inner))/w+cx1,r1*(cyd*(r1-r2)+cxd*Math.sqrt(d_inner))/w+cy1]
end
puts R.uniq.sort.map{|e|e*' '}