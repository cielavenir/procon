#!/usr/bin/ruby
N=gets.to_i
r=[*0...N]
c=[*0...N]
t=0
gets.to_i.times{
	z,x,y=gets.split.map &:to_i
	if z==3
		r,c=c,r
		t^=1
		next
	end
	x-=1
	y-=1
	if z==1
		r[x],r[y]=r[y],r[x]
	elsif z==2
		c[x],c[y]=c[y],c[x]
	elsif z==4
		r_=r[x]
		c_=c[y]
		r_,c_=c_,r_ if t==1
		p N*r_+c_
	end
}
