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

x=gets.to_i
p gets.split.map(&:to_i).map{|e|x.pow_binary_mod(e,1000003)}.reduce(:+)%1000003