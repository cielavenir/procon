#!/usr/bin/ruby
require 'prime'
M=10**8
a=Prime.each(M/2).to_a
r=0
a.length.times{|i|
	i.step(a.length-1){|j|
		break if a[i]*a[j]>M
		r+=1
	}
}
p r