#!/usr/bin/ruby
s=gets.chomp
l=0
r=s.size-1
k=0
while l<r
	if s[l]!=s[r]
		if s[l]=='x'
			l+=1
		elsif s[r]=='x'
			r-=1
		else
			p -1;exit
		end
		k+=1
	else
		l+=1
		r-=1
	end
end
p k
