#!/usr/bin/ruby
MOD = 1000000007
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
def comb(n,k)
if false
	r=1
	return 1 if k<1
	1.step(k){|i|
		r*=n-i+1
		r/=i
	}
	r%MOD
else
	#https://twitter.com/kagamiz/status/259654240740454400
	#1/a % p = a**(p-2)
	a=1;b=1
	return 1 if k<1
	1.step(k){|i|
		a=a*(n-i+1)%MOD
		b=b*i%MOD
	}
	a*pow_binary(b,MOD-2)%MOD
end
end

n,k=$<.map(&:to_i)
n+=k-1
k=n-k if k>n/2
p comb(n,k)