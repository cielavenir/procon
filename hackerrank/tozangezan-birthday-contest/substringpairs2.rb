#!/usr/bin/ruby
n,a=gets.split.map(&:to_i)
if n<2
	p 0
elsif
	p a**n%100000007
end