#!/usr/bin/env crystal

def solve(v,n,q,x)
	m=n//2;r=0_i64
	(1...n-m).each{|i|v[i]=0}
	(1...n-m).each{|i|x.each{|e|
		e<=i && (v[i]=(v[i]+v[i-e])%q)
	}}
	x.each{|e|([m-e,0].max...[n-e,m].min).each{|i|
		r=(r+1_i64*v[i]*v[n-i-e-1])%q
	}}
	r
end

def pow(x,y,q)
	z=1_i64
	while y>0
		y%2>0 && (z=z*x%q)
		x=x*x%q
		y//=2
	end
	z
end

n,m=gets.not_nil!.split.map &.to_i
x=gets.not_nil!.split.map &.to_i
m1=168647939;m2=592951213
v=[0]*(n-n//2);v[0]=1
r1=solve(v,n,m1,x);r2=solve(v,n,m2,x)
rm=(r2-r1+m2)*pow(m1.to_i64,m2-2,m2)%m2
puts rm*m1+r1
