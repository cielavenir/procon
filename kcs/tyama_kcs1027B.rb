#!/usr/bin/ruby
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

a,x,y=gets.split.map(&:to_i)
p a.pow_binary_mod(x.gcd(y),1000000007)-1