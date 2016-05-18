#!/usr/bin/env crystal
M=1000000007
s,t=ARGF.gets_to_end.split
m=t.to_i
a=[0]*m;a[z=0]=1
s.each_char{|c|
	d=c.to_i;f=d==0?1:0;z+=f;b=a.dup
	m.times{|j|k=(10*j+d)%m;b[k]=(b[k]+a[j]-f)%M;f=0}
	a=b
}
p (a[0]-1+z)%M