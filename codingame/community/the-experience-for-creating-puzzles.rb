#!/usr/bin/ruby
l,x,n=$<.map(&:to_i)
n*=300
if n<x
	puts [l,x-n]
else
	n-=x
	y=0
	l=(l+1..1/0.0).find{|i|
		y=(i*Math.sqrt(i)*10).to_i
		not n>=y && n-=y
	}
	puts [l,y-n]
end