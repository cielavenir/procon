#!/usr/bin/ruby
require 'rational'
a,b=gets.split.map(&:to_i)
r=0
while b>0
	g=a.gcd(b)
	a/=g;b/=g
	r+=a/b
	a,b=b,a-a/b*b
end
p r