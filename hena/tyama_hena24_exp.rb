#!/usr/bin/ruby
(1..10000).each{|n|
	(1..100).each{|x|
		(1..100).each{|y|
			r0=n/(x*y)
			r1=n/x/y
			r2=n/y/x
			if r0!=r1 || r1!=r2
				raise [n,x,y].join(',')
			end
		}
	}
}
