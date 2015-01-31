#!/usr/bin/ruby
cx,cy,r=gets.split.map(&:to_f)
gets.to_i.times{
	x1,y1,x2,y2=gets.split.map(&:to_f)
	if x1==x2
		#(x1 - cx)^2 + (y - cy)^2 = r^2
		#y^2 - 2cyy + cy^2 + (x1 - cx)^2 - r^2 = 0
		d=cy**2-(cy**2+(x1-cx)**2-r**2)
		y=[cy-Math.sqrt(d),cy+Math.sqrt(d)]
		puts [x1,y[0],x1,y[1]]*' '
	else
		a=(y2-y1)/(x2-x1)
		b=y1-a*x1
		#(x - cx)^2 + (ax + b-cy)^2 = r^2
		#x^2 - 2cxx + cx^2 + (ax)^2 + 2a(b-cy)x + (b-cy)^2 = r^2
		#(a^2+1)x^2 + (2ab-2acy-2cx)x + cx^2 + (b-cy)^2 - r^2 = 0
		s=a**2+1
		t=2*a*b-2*a*cy-2*cx
		u=cx**2+(b-cy)**2-r**2
		d=t**2-4*s*u
		x=[(-t-Math.sqrt(d))/2/s,(-t+Math.sqrt(d))/2/s]
		y=x.map{|e|a*e+b}
		puts [x[0],y[0],x[1],y[1]]*' '
	end
}