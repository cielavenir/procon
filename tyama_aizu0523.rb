#!/usr/bin/ruby
M=999
while(n=gets.to_i)>0
	a=[*1..(2*n)]
	b=n.times.map{gets.to_i}
	h=[b,a-b];f=0;m=0
	loop{
		x=h[f].map{|e|e>m ?e: M}.min
		if x<M then h[f]-=[x];m=x else m=0 end
		if h[f].size==0 then p h[1].size,h[0].size;break end
		f^=1
	}
end