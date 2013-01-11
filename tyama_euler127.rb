#!/usr/bin/ruby
require 'prime'
require 'rational'
s=0
rad=[]
1.step(119999){|c|
	rad[c]=c.prime_division.reduce(1){|s,e|s*=e[0]}
	if rad[c]>=c/2 then next end
	#if c%100==0 then p c end
	1.step(c/2-1){|a|
		b=c-a
		if rad[a]*rad[b]*rad[c]<c&&a.gcd(b)==1 then s+=c end
	}
}
p s