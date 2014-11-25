#!/usr/bin/ruby
class Fixnum
	def pow_binary_mod(y)
		x = self
		z = 1
		while y!=0
			z=z*x%$mod if y&1!=0
			x=x*x%$mod
			y>>=1
		end
		z
	end
	def /(n)
		self*n.pow_binary_mod($mod-2)%$mod
	end
end
n=gets.to_i
r=0
A=n.times.map{
	a=gets.split
	[a[0].to_i,a[1].to_i,10**a[0].size]
}
$mod=gets.to_i
A.each{|a,l,base|
	r=(r*base.pow_binary_mod(l))%$mod
	r=(r+a*(base.pow_binary_mod(l)-1)/(base-1))%$mod
	p r
}