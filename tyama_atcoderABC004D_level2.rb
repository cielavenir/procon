#!/usr/bin/ruby
p gets.split.map(&:to_i).map{|e|
	r=0
	x=1
	(e-1).times{|i|
		r+=x
		x+=1 if i%2==1
	}
	r
}.reduce(:+)