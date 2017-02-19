#!/usr/bin/ruby
l,*a=$<.read.split.map &:to_i
h={}
a.each{|i|
	h[i]=1
	r=[]
	while h[l]
		r<<l
		l-=1
	end
	puts r*' '
}
