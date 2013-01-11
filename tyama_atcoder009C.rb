#!/usr/bin/ruby
MOD=1777777777

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
 
def f(k)
if false
	[*0...k].permutation.reduce(0){|s,e|s += e.length.times.all?{|i|e[i]!=i} ? 1 : 0}
else
	#[1,0,1,2,9,44,265,1854,14833,133496,1334961][k]
	a=[1,0,1]
	return a[k] if k<3
	3.step(k){|i|a.shift;a<<(i-1)*(a[0]+a[1])%MOD}
	a[2]
end
end
 
n,k=gets.split.map(&:to_i)
p comb(n,k)*f(k)%MOD