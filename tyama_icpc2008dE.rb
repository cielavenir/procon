#!/usr/bin/ruby
EPS=1e-9
def cross(a,b) (a.conj*b).imag end
def dot(a,b) (a.conj*b).real end
def projection(l,p)
	t=dot(p-l[0],l[0]-l[1])/(l[0]-l[1]).abs2
	l[0]+t*(l[0]-l[1])
end
def intersectSP(s,p)
	(s[0]-p).abs+(s[1]-p).abs-(s[1]-s[0]).abs < EPS # triangle inequality
end
def distanceSP(s,p)
	r=projection(s,p)
	return (r-p).abs if intersectSP(s,r)
	[(s[0]-p).abs,(s[1]-p).abs].min
end
def intersectSS(l,m)
	a=cross(l[1]-l[0],m[1]-m[0])
	b=cross(l[1]-l[0],l[1]-m[0])
	pt=a.abs<EPS ? b.abs<EPS ? [l[0],l[1],m[0],m[1]] : [] : [m[0]+b/a*(m[1]-m[0])]
	pt.any?{|e|
		dot(l[0]-e,l[1]-e)<EPS && dot(m[0]-e,m[1]-e)<EPS
	}
end
def distanceSS(s,t)
	return 0 if intersectSS(s,t)
	[s.map{|e|distanceSP(t,e)}.min,t.map{|e|distanceSP(s,e)}.min].min
end
while(n=gets.to_i)>0
	sx,sy,ex,ey=gets.split.map(&:to_f)
	s=[Complex(sx,sy),Complex(ex,ey)]
	p n.times.map{
		f=0
		x1,y1,x2,y2,h=gets.split.map(&:to_f)
		a=[x1,x2].product([y1,y2]).map{|x,y|Complex(x,y)}
		a[2],a[3]=a[3],a[2]
		d=4.times.map{|i|
			f+=cross(a[i]-s[0],a[(i+1)%4]-s[0])<EPS ? 1 : 0
			distanceSS(s,[a[i],a[(i+1)%4]])
		}.min
		if f==4 #inside
			0
		elsif d>h
			(h*h+d*d)/h/2
		else
			d
		end
	}.min
end