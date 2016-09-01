#!/usr/bin/ruby
require 'prime'
class Integer
	def divisornum() self.prime_division.reduce(1){|s,(n,p)|s*(p+1)} end
end
p (gets.to_i**2).divisornum