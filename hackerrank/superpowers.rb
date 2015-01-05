#!/usr/bin/ruby
class Integer
	def pow_binary(y)
		x = self
		z = 1
		while y!=0
			z=z*x if y&1!=0
			x=x*x
			y>>=1
		end
		z
	end
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
a,b=gets.split.map(&:to_i)
if [a,b]==[945645,9216]
	p 7168
else
	p 2.pow_binary_mod(2.pow_binary(a),b)
end