#!/usr/bin/ruby
l=gets.to_i
b=l.times.map{gets.to_i}
r=[]
#l.times{|i| #lol lol lol ^^
	i=0
	a=[0]
	l.times{|j|
		a << (a.last^b[(i+j)%l])
	}
	if a.last==0
		r << a[0...l]
	end
#}
puts r.empty? ? -1 : r.min