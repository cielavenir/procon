#!/usr/bin/ruby
gets
s=gets.chomp
z=[0,0]
i=0
r=0
while i<s.size-1
	if s[i]!=s[i+1]
		i+=2
	else
		x=s[i].to_i
		if z[x]==0
			z[0]+=1
			z[1]+=1
			r+=1
		end
		z[x]-=1
		i+=1
	end
end
p r