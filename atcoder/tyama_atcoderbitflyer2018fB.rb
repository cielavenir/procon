#!/usr/bin/ruby
(n,),x,*q=$<.map{|e|e.split.map &:to_i}
a=[0]
x.each{|e|a<<a[-1]+e}
q.each{|c,d|
	m=(0...n).bsearch{|i|c<x[i]}||n
	l=(0...n).bsearch{|i|c-d<=x[i]}||n
	r=(0...n).bsearch{|i|c+d<x[i]}||n
	p (l+n-r)*d+a[l]+a[r]-2*a[m]+(2*m-l-r)*c
}
