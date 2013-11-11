#!/usr/bin/ruby
MOD = 1000000007
class Fixnum
	def pow_binary_mod(y)
		x = self
		z = 1
		while y != 0
			while y % 2 == 0
				x = x * x % MOD
				#y = y / 2
				y = y >> 1
			end
			y = y - 1
			z = z * x % MOD
		end
		z
	end
end
gets.to_i.times{
	p 4.pow_binary_mod(gets.to_i.to_s(2).to_i)
}