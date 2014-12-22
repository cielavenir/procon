#!/usr/bin/ruby
def solve(n)
	fact=[1]
	a=[0]
	1.step(n){|i|
		fact[i]=i*fact[i-1]
		a[i]=(i-1)*fact[i-1]+i*a[i-1]
	}
	a[n]
end
if __FILE__==$0
	p solve(7)
end