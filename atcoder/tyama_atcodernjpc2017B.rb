#!/usr/bin/ruby
h,w,n=gets.split.map(&:to_i)
r=0
a={}
n.times{
	y,x=gets.split.map(&:to_i)
	s=y==1||y==h
	t=x==1||x==w
	r+=s&&t ? 2 : s||t ? 3 : 4
	r-=1 if h==1
	r-=1 if w==1
	a[[y,x]]=1
}
a.each_key{|y,x|
	[[1,0],[0,1]].each{|dy,dx|
		r-=1 if a[[y+dy,x+dx]]
	}
}
p 2*h*w-h-w-r
