#!/usr/bin/ruby
MOD=1000000007

def pow_binary(x,y)
	z = 1
	while y!=0
		z=z*x%MOD if y&1!=0
		x=x*x%MOD
		y>>=1
	end
	z
end

gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	p pow_binary(a%MOD,b%~-MOD)
}