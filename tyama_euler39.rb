#!/usr/bin/ruby
p 4.step(1000).map{|x|[
	1.step(x/2-1).map{|i|
		i.step(x-1-i).select{|j|k=x-i-j;i*i+j*j==k*k}.count
	}.reduce(&:+),x
]}.max[1]