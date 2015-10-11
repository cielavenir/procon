#!/usr/bin/ruby
L,C,n,*p=$<.read.split.map(&:to_i)
if (s=p.reduce(:+))<=L
	p s*C
else
	r=0
	h={0=>[0,0]}
	hi={0=>0}
	cur=0
	lc=C
	C.times{|i|
		s=0
		while s+p[cur]<=L
			s+=p[cur]
			cur=(cur+1)%n
		end

		r+=s
		#Cで場合分けしてる辺り嘘解法臭大.
		if C>1000000&&h.has_key?(cur)
			block=i-h[cur][0]
			r=h[cur][1] + (C-h[cur][0])/block * (r-h[cur][1])
			lc=h[cur][0]+(C-h[cur][0])/block*block+1
			break
		else
			h[cur]=[i,r]
			hi[i+1]=r
		end
	}
	(lc...C).each{|i|
		s=0
		while s+p[cur]<=L
			s+=p[cur]
			cur=(cur+1)%n
		end
		r+=s
	}
	p r
end