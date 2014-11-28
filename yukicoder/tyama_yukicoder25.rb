#!/usr/bin/ruby
require 'rational'
n=gets.to_i
m=gets.to_i
g=n.gcd(m)
n/=g
m/=g
n/=10 while n%10==0
m/=10 while m%10==0
div=Hash.new(0)
while m%2==0
	m/=2
	div[2]+=1
end
while m%5==0
	m/=5
	div[5]+=1
end
if m!=1
	p -1
	exit
end
n%=10
div[2].times{|i|
	n*=5
	n = n%10==0 ? n/10 : n%10
}
div[5].times{|i|
	n*=2
	n = n%10==0 ? n/10 : n%10
}
p n