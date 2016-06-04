#!/usr/bin/ruby
require 'prime'
class Integer
	def divisornum() self.prime_division.reduce(1){|s,(n,p)|s*(p+1)} end
	def divisorsum() self.prime_division.reduce(1){|s,(n,p)|s*(n**(p+1)-1)/(n-1)} end
	def totient()    self.prime_division.reduce(1){|s,(n,p)|s*(n-1)*n**(p-1)} end

	def derivative() self.prime_division.reduce(0){|s,(n,p)|s+self*p/n} end
end

puts (1..gets.to_i).map(&:divisorsum).reduce(:+)