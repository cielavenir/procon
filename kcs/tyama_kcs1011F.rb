#!/usr/bin/ruby
n,s=gets.split
n=n.to_i-1
if s=='FizzBuzz'
	p 15*(n+1)
elsif s=='Fizz'
	p 3*(n/4*5+n%4+1)
elsif s=='Buzz'
	p 5*(n/2*3+n%2+1)
end