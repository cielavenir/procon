#!/usr/bin/ruby
n,m,l=gets.split.map(&:to_i)
a=n.times.map{gets.to_i}
m.times{
	e=gets.to_i
	while a.size>0&&a[0]<=e
		e-=a[0]
		a.shift
	end
	break if a.size==0
	if l<=e
		a[0]-=e-l
	end
}
p n-a.size