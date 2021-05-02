#!/usr/bin/ruby
T=2*10**12
a,k=gets.split.map &:to_i
if k==0
	p T-a
else
	i=0
	while a<T
		a+=1+k*a
		i+=1
	end
	p i
end