#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	a=gets.to_i.prime_division.partition{|n,p|n==2}
	if a[0].empty?
		p 0
	else
		n=a[0][0][1]
		p n*a[1].map{|e|e.last+1}.reduce(1,:*)
	end
}