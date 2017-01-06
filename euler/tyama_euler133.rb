#!/usr/bin/ruby
require 'prime'

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

raise if gets.to_i!=1
n=gets.to_i
p Prime.each(n-1).select{|e|10.pow_binary_mod(10**20,e)>1}.reduce(0,:+)+[2,3,5].select{|e|e<n}.reduce(0,:+)
__END__
1
100000
