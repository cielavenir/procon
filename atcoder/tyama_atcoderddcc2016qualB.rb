#!/usr/bin/ruby
r,n,m=gets.split.map &:to_i
c=n/2.0
z=0
(1...n+m).map{|e|
	h=[e,e-m].map{|f|n>f&&f>0?(f-c).abs: 1e9}.min/c
	z+=2*r*Math.sqrt(1-h*h)
}
p z
