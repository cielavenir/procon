#!/usr/bin/ruby
X = 12 # 10
MOD = 10**X
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
r=0
gets.to_i.times{
	a,b,c,d=gets.split.map(&:to_i)
	r=(r+a*b.pow_binary_mod(c)+d)%MOD
}
puts '%0*d'%[X,r]
__END__
1
28433 2 7830457 1