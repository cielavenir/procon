#!/usr/bin/ruby
n=gets.to_i
ans=1
now=0
b=1
mod = 
n.times{|i|
	a=gets.to_i
	b*=10
	if now>=b
		now+=a*b
	else
		ans*=now+1
		b=1
		now=a
	end
}
p (ans*(now+1)-1)%1000000007