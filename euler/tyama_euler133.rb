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
end

p Prime.each(100000).select{|e|10.pow_binary_mod(10**20,e)>1}.reduce(:+)+2+3+5