#!/usr/bin/ruby
N=gets.to_i
p 10**N-1
(10**N).times{|_i|
	i=_i
	N.times{|j|
		n=i/10**(N-j-1)%10
		print n
		i=i%10**(N-j-1)
		i=10**(N-j-1)-i-1 if n%2!=0
	}
	puts
}