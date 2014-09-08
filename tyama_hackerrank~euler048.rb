#!/usr/bin/ruby
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

n=gets.to_i
p (1..n).reduce{|s,i|(s+i.pow_binary_mod(i,10000000000))%10000000000}