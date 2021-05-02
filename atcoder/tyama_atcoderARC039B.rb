#!/usr/bin/ruby
MOD = 1000000007
def pow_binary(x,y) #is11.rb
	z = 1
	while y!=0
		z = z*x%MOD if y%2!=0
		x = x*x%MOD
		y>>=1
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

n,k=gets.split.map(&:to_i)
p n>k ? comb(n+k-1,n-1) : comb(n,k%n)