#!/usr/bin/ruby
require 'prime'

class Integer
	def pow_binary_mod(y,m)
		x = self
		z = 1
		while y != 0
			while y % 2 == 0
				x = x * x % m
				y = y / 2
			end
			y = y - 1
			z = z * x % m
		end
		z
	end
end

p Prime.each(100000).select{|e|10.pow_binary_mod(10**20,e)>1}.reduce(:+)+2+3+5