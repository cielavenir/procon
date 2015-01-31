#!/usr/bin/ruby
N,L=gets.split.map(&:to_i)
curt=curd=0
N.times{
	x,w,t=gets.split.map(&:to_i)
	curt+=x-curd
	curd=x
	a,b=curt.divmod(2*t)
	c,d=(curt+w).divmod(2*t)
	curt=(curt+2*t-1)/(2*t)*(2*t) unless b<=t && d<=t
	curt+=w
	curd+=w
}
p L-curd+curt