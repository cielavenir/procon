#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	p (gets.to_i.prime_division.reduce(1){|s,e|s*=e[1]*2+1}+1)/2
}