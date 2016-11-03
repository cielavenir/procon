#!/usr/bin/ruby
require 'prime'
LIMIT=10**9
p 367567200*2

z=Prime.each(50).to_a
n=1
z.each{|e|
	break if n*e>LIMIT
	n*=e
}
p n*3
p n*29/7
p n*31/11

96.times{
	a=z.sample(7).sort
	n=1
	a.each{|e|
		break if n*e>LIMIT
		n*=e
	}
	1.times{
		break if n*a[2]>LIMIT
		n*=a[2]
	}
	3.times{
		break if n*a[1]>LIMIT
		n*=a[1]
	}
	loop{
		break if n*a[0]>LIMIT
		n*=a[0]
	}
	p n
}
