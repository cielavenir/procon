#!/usr/bin/ruby
h={}
cap=cur=0
gets.to_i.times{
	x,y=gets.split
	y=y.to_i
	if x=='+' && !h[y]
		cur+=1
		h[y]=1
	elsif x=='-' && h[y]
		cur-=1
		h[y]=nil
	elsif x=='-' && !h[y]
		cap+=1
	end
	cap=[cap,cur].max
}
p cap