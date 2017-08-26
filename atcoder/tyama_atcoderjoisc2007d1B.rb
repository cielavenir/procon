#!/usr/bin/ruby
require 'prime'
n=gets.to_i
z=n.prime_division.max[0]
n/=z
p [z,1.step(n).find{|i|
	next if i==z
	i.prime_division.each{|x,p|p.times{n/=x if n%x==0}}
	n==1
}].max
