#!/usr/bin/ruby
gets
a=[0]+gets.split.map(&:to_i)
b=a.sort
u=[0]
v=[0]
(a.size-1).times{|i|
	u[i+1]=u[i]+a[i+1]
	v[i+1]=v[i]+b[i+1]
}
gets.to_i.times{
	a=gets.split.map(&:to_i)
	x=a[0]==1?u:v
	p x[a[2]]-x[a[1]-1]
}