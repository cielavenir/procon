#!/usr/bin/ruby
require 'prime'
while (n=gets.to_i)>0
	p n.prime_division.max.first
end