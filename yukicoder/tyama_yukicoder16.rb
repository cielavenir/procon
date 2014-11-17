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

x=gets.to_i
p gets.split.map(&:to_i).map{|e|x.pow_binary_mod(e,1000003)}.reduce(:+)%1000003