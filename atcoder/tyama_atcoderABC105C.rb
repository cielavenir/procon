#!/usr/bin/ruby
n=gets.to_i
s=n==0?'0':''
i=1
while n!=0
	if n%(i*2)!=0
		n-=i
		s<<?1
	else
		s<<?0
	end
	i*=-2
end
puts s.reverse
