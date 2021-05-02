#!/usr/bin/ruby
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

N=gets.to_i
A=gets.split.map(&:to_i)
if A[0]>0||A.count(0)>1
	p 0
else
	C=[0]*N
	A.each{|e|C[e]+=1}
	r=1
	M=1000000007
	1.step(N-1){|i|
		r=r*(2.pow_binary_mod(C[i-1],M)-1).pow_binary_mod(C[i],M)*2.pow_binary_mod(C[i]*(C[i]-1)/2,M)%M
	}
	p r
end
