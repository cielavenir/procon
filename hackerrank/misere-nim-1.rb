#!/usr/bin/ruby
gets.to_i.times{
	gets
	a=gets.split.map(&:to_i)
	xor=a.reduce(:^)
	puts (a.any?{|e|e>1} ? xor==0 : xor==1) ? :Second : :First
}