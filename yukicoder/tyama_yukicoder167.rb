#!/usr/bin/ruby
MOD = 10
class Integer
	def pow_binary_mod(y)
		x = self
		z = 1
		while y!=0
			z=z*x%MOD if y&1!=0
			x=x*x%MOD
			y>>=1
		end
		z
	end
end
p gets.to_i.pow_binary_mod gets.to_i