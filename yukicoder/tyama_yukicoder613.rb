#!/usr/bin/env ruby
#cf: codejam 2008r1aC Numbers
def pow(x,y,m)
	z=1
	while y>0
		z=z*x%m if y%2>0
		x=x*x%m
		y/=2
	end
	z
end
k,M=gets.split.map &:to_i
k=pow(2,k,M*M-1)
def mul(a,b)
	[(a[0]*b[0]+3*a[1]*b[1])%M,(a[1]*b[0]+b[1]*a[0])%M]
end
x=[2,1]
e=[1,0]
while k>0
	e=mul(e,x) if k%2>0
	x=mul(x,x)
	k/=2
end
p 2*~-e[0]%M
