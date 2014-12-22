#!/usr/bin/ruby
require'rational'
n=gets.to_i
m=gets.to_i
g=n.gcd(m)
n/=g
m/=g
n/=10 while n%10==0
m/=10 while m%10==0
n%=10
[2,5].each{|e|
	d=0
	while m%e==0
		m/=e
		d+=1
	end
	d.times{|i|
		n*=10/e
		n=n%10==0 ? n/10 : n%10
	}
}
p m==1?n:-1