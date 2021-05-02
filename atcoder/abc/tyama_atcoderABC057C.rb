#!/usr/bin/ruby
n=gets.to_i
i=1
while i*i<=n
	r=i if n%i==0
	i+=1
end
p (n/r).to_s.size
