#!/usr/bin/ruby
a=[1,1,2]
3.step(30){|i|a<<a[i-1]+a[i-2]+a[i-3]}
while (n=gets.to_i)>0
	puts (a[n]+3649)/3650
end