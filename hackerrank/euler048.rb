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

n=gets.to_i
p (1..n).reduce{|s,i|(s+i.pow_binary_mod(i,10000000000))%10000000000}