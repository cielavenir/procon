#!/usr/bin/ruby
n=gets.to_i
h={}
i=1
while i*i<=n
	if n%i==0
		h[i.to_s+(n/i).to_s]=1
		h[(n/i).to_s+i.to_s]=1
	end
	i+=1
end
p h.size
