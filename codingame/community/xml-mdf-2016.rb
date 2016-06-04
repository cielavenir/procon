#!/usr/bin/ruby
h=Hash.new(0)
d=1
gets.scan(/-?\w/).each{|e|
	if e[0]!=?-
		h[e[0]]+=Rational(1,d)
		d+=1
	else
		d-=1
	end
}
puts h.min_by{|k,v|[-v,k]}[0]