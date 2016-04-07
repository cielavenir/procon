#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	n=gets.to_i
	a=n.prime_division
	f=a.all?{|n,p|p%2==0} ? 1 : 0
	den=a.reduce(1){|s,(n,p)|s*(p+1)}
	b=[[],[]]
	a.each{|n,p|
		b[n%2]<<p/2 if p>1
	}
	x=(b[0]+b[1]).reduce(1){|s,p|s*(p+1)}-b[1].reduce(1){|s,p|s*(p+1)}-f
	x=0 if x<0 # ex) n==9
	y=den-1
	if x==0
		p 0
	else
		g=x.gcd(y)
		x/=g
		y/=g
		puts '%d/%d'%[x,y]
	end
}