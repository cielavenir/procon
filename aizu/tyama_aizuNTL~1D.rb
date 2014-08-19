#!/usr/bin/ruby
require 'prime'
class Integer
	def totient() self.prime_division.reduce(1){|s,e|s*(e[0]-1)*e[0]**(e[1]-1)} end
end
p gets.to_i.totient