#!/usr/bin/ruby
n=gets.to_i
r=i=1
while i*i<=n
	r=i if n%i==0
	i+=1
end
puts '%d %d'%[r,n/r]