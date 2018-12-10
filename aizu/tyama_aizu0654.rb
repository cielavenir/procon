#!/usr/bin/ruby
n=gets.to_i
s=gets.chomp
r=0
i=1
while i<n
	if s[i]!=s[i-1]
		r+=1
		i+=1
	end
	i+=1
end
p r
