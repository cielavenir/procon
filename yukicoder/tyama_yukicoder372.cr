#!/usr/bin/env crystal
M=1000000007
s=gets.not_nil!.chomp
m=gets.not_nil!.to_i
a=[1]+[0]*~-m
z=0
s.size.times{|i|
	d=s[i].to_i
	z+=1 if d==0
	b=a.dup
	m.times{|j|
		k=(10*j+d)%m
		b[k]=(b[k]+a[j]-(d==0&&j==0?1:0))%M
	}
	a=b
}
p (a[0]-1+z)%M
# ((d+2)/(d+1)-1)*((j+2)/(j+1)-1)