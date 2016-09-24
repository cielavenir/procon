#!/usr/bin/ruby
w,h,t=gets.split.map(&:to_i)
z=Hash.new(0)
r=0
gets.to_i.times{
	x,y,_=gets.split.map(&:to_i)
	z[[x,y]]+=1
}
h.times{|i|
	a=gets.split.map(&:to_i)
	w.times{|j|
		r+=a[j]*z[[j,i]]
	}
}
p r
