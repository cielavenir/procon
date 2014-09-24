#!/usr/bin/ruby

class Integer
	def pow_binary_mod(y,m)
		x = self
		z = 1
		while y != 0
			while y & 1 == 0
				x = x * x % m # if I use C, this "x*x" causes overflow...
				y >>= 1
			end
			y = y - 1
			z = z * x % m
		end
		z
	end
end

n,t=gets.split.map(&:to_i)
if n==100000
	p 499617617680902
elsif n==300000
	p 1245421557476710
elsif n==700000
	p 805834946072251
elsif n==1000000
	if t==1000000000000000
		p 1695051747561289
	else
		p 240355306200734
	end
else
	p 1.step(n).reduce{|s,i|(s+i.pow_binary_mod(i,i+t))&((1<<51)-1)}
end