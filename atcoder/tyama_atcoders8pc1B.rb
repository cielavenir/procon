#!/usr/bin/ruby
require 'rational'
H,W,N=gets.split.map(&:to_i)
A=N.times.map{
	Rational(*gets.split.map(&:to_i))
}.sort
r=[]
if A.size.even?
	x=A.size/2
	1.upto(H-1){|h|
		z=Rational(h,W)
		r<<'(%d,%d)'%[h,W] if A[x-1]<z&&z<A[x]
	}
	1.upto(W){|w|
		z=Rational(H,w)
		r<<'(%d,%d)'%[H,w] if A[x-1]<z&&z<A[x]
	}
end
puts r.empty? ? -1 : r