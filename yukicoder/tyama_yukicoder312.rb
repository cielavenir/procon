#!/usr/bin/ruby
n=gets.to_i
i=3
while i*i<=n
	if n%i==0
		p i
		exit
	end
	i+=1
end
p n>4&&n%2==0 ? n/2 : n