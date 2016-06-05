#!/usr/bin/ruby
if false
	require 'prime'
	def prime_division(n) n.prime_division end
else
	def prime_division(n)
		IO.popen('factor '+n.to_s){|io|
			a=[]
			line=io.gets
			line.split[1..-1].group_by{|e|e}.each{|k,v|a<<[k.to_i,v.size]}
			a
		}
	end
end
def divisor_totient(a,d,n,t)
	return to_enum(:divisor,a,d,n,t) if !block_given?
	if d==a.size
		yield n,t
	else
		(0..a[d][1]).each{|i|
			divisor_totient(
				a,d+1,
				n*a[d][0]**i,
				i==0 ? t : t*(a[d][0]-1)*a[d][0]**(i-1),
				&proc
			)
		}
	end
end
def pow(x,y,m)
	z=1
	while y>0
		z=z*x%m if y%2>0
		x=x*x%m
		y/=2
	end
	z
end

cache={}
M=1000000007
H,W,K=gets.split.map(&:to_i)
A=prime_division(H)
B=prime_division(W)
r=0
divisor_totient(A,0,1,1){|a,at|
	divisor_totient(B,0,1,1){|b,bt|
		key=W*H/a.lcm(b)
		cache[key]=pow(K,key,M) if !cache.has_key?(key)
		r=(r+at*bt*cache[key])%M
	}
}
p r*pow(W*H,M-2,M)%M