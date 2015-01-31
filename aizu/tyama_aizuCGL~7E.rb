#!/usr/bin/ruby
cx1,cy1,r1=gets.split.map(&:to_f)
cx2,cy2,r2=gets.split.map(&:to_f)
#(x - cx1)^2 + (y - cy1)^2 - r1^2 = (x - cx2)^2 + (y - cy2)^2 - r2^2
#2(-cx1+cx2)x + 2(-cy1+cy2)y + cx1^2 + cy1^2 - r1^2 - cx2^2 - cy2^2 + r2^2 = 0
X=2*(cx2-cx1)
Y=2*(cy2-cy1)
Z=cx1**2+cy1**2-r1**2-cx2**2-cy2**2+r2**2
x1,y1,x2,y2=if Y==0
	[-Z/X,0,-Z/X,1]
else
	a=-X/Y;b=-Z/Y
	[0,b,1,a+b]
end
#gets.to_i.times{
	if x1==x2
		#(x1 - cx1)^2 + (y - cy1)^2 = r1^2
		#y^2 - 2cy1y + cy1^2 + (x1 - cx1)^2 - r1^2 = 0
		d=cy1**2-(cy1**2+(x1-cx1)**2-r1**2)
		y=[cy1-Math.sqrt(d),cy1+Math.sqrt(d)]
		puts [x1,y[0],x1,y[1]]*' '
	else
		a=(y2-y1)/(x2-x1)
		b=y1-a*x1
		#(x - cx1)^2 + (ax + b-cy1)^2 = r^2
		#x^2 - 2cx1x + cx1^2 + (ax)^2 + 2a(b-cy1)x + (b-cy1)^2 = r1^2
		#(a^2+1)x^2 + (2ab-2acy1-2cx1)x + cx1^2 + (b-cy1)^2 - r1^2 = 0
		s=a**2+1
		t=2*a*b-2*a*cy1-2*cx1
		u=cx1**2+(b-cy1)**2-r1**2
		d=t**2-4*s*u
		x=[(-t-Math.sqrt(d))/2/s,(-t+Math.sqrt(d))/2/s]
		y=x.map{|e|a*e+b}
		puts [x[0],y[0],x[1],y[1]]*' '
	end
#}