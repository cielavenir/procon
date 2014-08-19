#!/usr/bin/ruby
require 'prime'
class Integer
	def totient() self.prime_division.reduce(1){|s,e|s*(e[0]-1)*e[0]**(e[1]-1)} end
end
a=[0,2];s=2
(2..10**6).each{|i|a<<s+=i.totient}
gets.to_i.times{p a[gets.to_i]}