#!/usr/bin/ruby
X=99
x=t=0
(1..1/0.0).each{|i|
	a=i.to_s.chars
	b=a.sort
	if a!=b && a!=b.reverse
		x+=1
	end
	t+=1
	if x*100==X*t
		p i
		exit
	end
}