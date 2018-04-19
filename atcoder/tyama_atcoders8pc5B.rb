#!/usr/bin/ruby
r=1e9
n,m=gets.split.map &:to_i
a=$<.map{|e|e.split.map &:to_i}
[*0...n+m].combination(2){|i,j|
	x=a[i];y=a[j]
	z=Math.hypot(x[0]-y[0],x[1]-y[1])
	r=[r,n<=i&&n<=j ? z/2 : n<=i ? z-y[2] : n<=j ? z-x[2] : [x[2],y[2]].min].min
}
p r
