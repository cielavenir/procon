#!/usr/bin/ruby
require 'prime'
require 'rational'
class Integer
	def derivative
		(self*self.prime_division.map{|x,y|Rational(y,x)}.reduce(0,:+)).to_i
	end
end
p 1.step(100).map{|i|[i,i.gcd(i.derivative)]}