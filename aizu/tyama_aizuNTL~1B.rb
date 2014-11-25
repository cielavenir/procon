#!/usr/bin/ruby
MOD=1000000007
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
x,y=gets.split.map(&:to_i)
p x.pow_binary_mod(y)