#!/usr/bin/ruby
n,m,*a=$<.read.split.map &:to_i
r=s=0
200.times{
	b=a.sample(m)
	x=b.reduce(:^)
	if x>s
		s=x
		r=b
	end
}
puts r*' '
