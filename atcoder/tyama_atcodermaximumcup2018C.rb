#!/usr/bin/ruby
n,*a=$<.map &:to_i
a.map!{|e|e-1}
h={}
r=0
n.times{|i|
	if !h[i]
		h[i]=1
		j=a[i]
		l=1
		while j!=i
			h[j]=1
			j=a[j]
			l+=1
		end
		if l%2>0
			p -1
			exit
		end
		r+=l/2
	end
}
p r
