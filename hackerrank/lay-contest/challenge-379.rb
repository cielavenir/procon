#!/usr/bin/ruby
require "date"
gets.to_i.times{
	x,y,z,w=gets.split.map(&:to_i)
	a=Date.new(2016,x,y)
	b=Date.new(2016,z,w)
	h={}
	while a<=b
		h[Rational(a.month,a.day)]=1
		a+=1
	end
	p h.size
}