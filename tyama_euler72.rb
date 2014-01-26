#!/usr/bin/ruby
require 'prime'
class Integer
	def totient() self.prime_division.reduce(1){|s,e|s*(e[0]-1)*e[0]**(e[1]-1)} end
end
p (2..1000000).reduce(0){|s,n|s+n.totient}