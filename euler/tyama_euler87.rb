#!/usr/bin/ruby
require 'prime'
M=50000000
a=Prime.each(9999).to_a
h={}
i=0;while a[i]**2 < M
	j=0;while a[i]**2+a[j]**3 < M
		k=0;while a[i]**2+a[j]**3+a[k]**4 < M
			h[a[i]**2+a[j]**3+a[k]**4]=1
			k+=1
		end
		j+=1
	end
	i+=1
end
p h.size