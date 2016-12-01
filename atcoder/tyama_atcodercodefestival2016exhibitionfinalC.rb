#!/usr/bin/ruby
h={}
r=t=0
gets;$<.each{|_|
	n=_.to_i
	h[n^(n-1)]=1
	t^=n
}
29.downto(0){|i|
	t[i]==0&&next
	!h[k=(1<<-~i)-1]&&(p -1;exit)
	t^=k
	r+=1
}
p r
