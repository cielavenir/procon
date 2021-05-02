#!/usr/bin/ruby
n,a,b,*h=`dd`.split.map &:to_i
p (1..10**9).bsearch{|t|
	r=0
	h.each{|e|
		r+=[0,(e-b*t+a-b-1)/(a-b)].max
	}
	r<=t
}
