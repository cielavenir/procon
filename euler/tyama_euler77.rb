#!/usr/bin/ruby
require 'prime'
primes=Prime.each(999).to_a
2.upto(1/0.0){|i|
	w=Array.new(i+1,0)
	w[0]=1
	primes.each{|e|
		e.step(i){|j|
			w[j]+=w[j-e]
		}
	}
	if w[i]>5000 then p i;exit end
}