#!/usr/bin/ruby
MOD=10

def pow_binary(x,y) #is11.rb
	z = 1
	while y != 0
		while y % 2 == 0
			x = x * x % MOD
			y = y / 2
		end
		y = y - 1
		z = z * x % MOD
	end
	z
end

gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	p pow_binary(a,b)
}