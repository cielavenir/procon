#!/usr/bin/ruby
a=[1,4,12,38]
n,m=gets.split.map(&:to_i)
if m==1
	1.step(100){|i|a[i]=2*a[i-1]}
else
	4.step(100){|i|a[i]=4*a[i-1]-3*a[i-2]+2*a[i-3]+a[i-4]}
end
p a[n]%1000000