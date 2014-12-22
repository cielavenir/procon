#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	p gets.to_i.prime_division.reduce(1){|s,e|s*(e[0]**(e[1]+1)-1)/(e[0]-1)}
}