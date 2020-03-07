#!/usr/bin/ruby
n=gets.to_i
a=[n]
while n>1
	if n%2==0
		a<<n=n/2
	else
		a<<n=3*n+1
	end
end
p *[a.size-1,a.max]
