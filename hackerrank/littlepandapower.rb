#!/usr/bin/ruby
require 'prime'
class Integer
	def pow_binary_mod(y,m)
		x = self
		z = 1
		while y!=0
			z=z*x%m if y&1!=0
			x=x*x%m
			y>>=1
		end
		z
	end
	def totient() self.prime_division.reduce(1){|s,e|s*(e[0]-1)*e[0]**(e[1]-1)} end
end
gets.to_i.times{
	a,b,c=gets.split.map(&:to_i)
	if b<0
		a=a.pow_binary_mod(c.totient-1,c)
		b=-b
	end
	p a.pow_binary_mod(b,c)
}