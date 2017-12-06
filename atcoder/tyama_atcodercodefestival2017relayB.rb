#!/usr/bin/ruby
n,q=gets.split.map &:to_i
q.times{
	a,b=gets.split.map &:to_i
	if n==1
		p [a,b].min
	else
		while a!=b
			a>b&&(a,b=b,a)
			b=(b+n-2)/n
		end
		p a
	end
}
