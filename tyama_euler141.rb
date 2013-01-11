#!/usr/bin/ruby
M=10**12
h={}
i=1
while i*(i+(i+1)**3)<M
	j=i+1
	while i+(i+j**3)<M
		k=1
		while (t=i*k*(i+j**3*k))<M
			h[t]=1 if Math.sqrt(t).to_i**2==t
			k+=1
		end
		j+=1
	end
	i+=1
end
p h.keys.reduce(:+)