#!/usr/bin/ruby
require 'prime'
N=3
primes=Prime.each.lazy.drop_while{|e|e<10**(N-1)}.take_while{|e|e<10**N}.to_a
p primes.permutation(N).count{|a|
	m=a.map{|e|
		e.to_s.split('')
	}.transpose.map{|e|
		e.join.to_i
	}
	m.uniq.size==m.size && m.all?{|e|primes.include?(e) && !a.include?(e)}
} # 29490