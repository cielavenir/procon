#!/usr/bin/ruby
require 'prime'
class Integer
	def sopfr()      self.prime_division.reduce(0){|s,(n,p)|s+(n*p)} end
	def factornum()  self.prime_division.reduce(0){|s,(n,p)|s+p} end
	def dfactornum() self.prime_division.reduce(0){|s,(n,p)|s+1} end
	def sopf()       self.prime_division.reduce(0){|s,(n,p)|s+n} end

	def divisornum() self.prime_division.reduce(1){|s,(n,p)|s*(p+1)} end
	def divisorsum() self.prime_division.reduce(1){|s,(n,p)|s*(n**(p+1)-1)/(n-1)} end
	def totient()    self.prime_division.reduce(1){|s,(n,p)|s*(n-1)*n**(p-1)} end

	def derivative() self.prime_division.reduce(0){|s,(n,p)|s+self*p/n} end
end
 
n=gets.to_i
p (1..1/0.0).find{|e|e.divisornum==n}