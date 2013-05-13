#!/usr/bin/ruby
require 'rational'
x,y=gets.split('/').map(&:to_i)
d=x.gcd(y)
x/=d;y/=d
a=(2*x-y)/(y*y)
a=1 if a<=0
f=nil
loop{
	n=a*y
	m=n*(n+1)/2-a*x
	a+=1
	next if m<1
	break if n<m
	puts [n,m]*' '
	f=1
}
puts 'Impossible' if !f