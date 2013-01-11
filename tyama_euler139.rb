#!/usr/bin/ruby
M=10**8
r=0
3.step(M,2){|n|
	1.step(n,2){|m|
		next if n.gcd(m)>1
		a=m*n;b=(n**2-m**2)/2;c=(n**2+m**2)/2
		if a+b+c>M && m==1 then p r;exit end
		r+=M/(a+b+c) if c%(b-a)==0
	}
}