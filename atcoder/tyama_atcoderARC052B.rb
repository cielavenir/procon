#!/usr/bin/ruby
calc=->r,h0,h{h<0 ? 0 : Math::PI/3*h*(r*h/h0)**2}
N,Q=gets.split.map &:to_i
A=N.times.map{gets.split.map &:to_f}
Q.times{
	a,b=gets.split.map &:to_f
	s=0
	A.each{|x,r,h|
		h0=x+h-[a,x].max
		r=r*h0/h
		s+=calc[r,h0,h0]-calc[r,h0,x+h-[b,x+h].min] if !(x+h<=a||b<=x)
	}
	p s
}