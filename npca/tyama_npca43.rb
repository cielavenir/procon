#!/usr/bin/ruby
require 'prime'
while(n=gets.to_i)>0
	print n
	puts n.prime? ? ' is prime!' : ' is not prime...'
end