#!/usr/bin/ruby
n=gets.to_i
c=gets.split.map &:to_i
a=[0]*n
gets.to_i.times{|i|
	t,x,d=gets.split.map &:to_i
	t=-1 if t==2
	x-=1
	a[x]+=t*d
	if a[x]<0||c[x]<a[x]
		p x+1
		exit
	end
}
p 0
