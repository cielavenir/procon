#!/usr/bin/ruby
require 'prime'
primes=Prime.each(999).to_a
z=[0]*1001
2.upto(1000){|i|
	w=Array.new(i+1,0)
	w[0]=1
	primes.each{|e|
		e.step(i){|j|
			w[j]+=w[j-e]
		}
	}
	#if w[i]>5000 then p i;exit end
	z[i]=w[i]
}
gets.to_i.times{p z[gets.to_i]}
__END__
1
71