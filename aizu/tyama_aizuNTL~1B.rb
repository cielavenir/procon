#!/usr/bin/ruby
class Fixnum
	def pow_binary_mod(y)
		x = self
		z = 1
		while y != 0
			while y % 2 == 0
				x = x * x % 1000000007
				#y = y / 2
				y = y >> 1
			end
			y = y - 1
			z = z * x % 1000000007
		end
		z
	end
end
x,y=gets.split.map(&:to_i)
p x.pow_binary_mod(y)