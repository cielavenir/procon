#!/usr/bin/ruby
puts$<.map{|l|
	l=~/(-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+)/
	x=[$1,$3,$5,$7].map(&:to_i)
	y=[$2,$4,$6,$8].map(&:to_i)
	f=false

	#4 points are not necessarily clockwise.
[1,2,3].permutation{|a,b,c|
	x1=(x[0]-x[a])**2;x2=(x[a]-x[b])**2;x3=(x[b]-x[c])**2;x4=(x[c]-x[0])**2;x5=(x[0]-x[b])**2
	y1=(y[0]-y[a])**2;y2=(y[a]-y[b])**2;y3=(y[b]-y[c])**2;y4=(y[c]-y[0])**2;y5=(y[0]-y[b])**2
	z1=x1+y1;z2=x2+y2;z3=x3+y3;z4=x4+y4;z5=x5+y5
	f|=z1==z2&&z2==z3&&z3==z4&&z1*2==z5
}
	f
}