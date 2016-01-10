#!/usr/bin/ruby
n,k,*a=$<.read.split.map &:to_i
r=x=j=0
x=1
n.times{|i|
	m=a[i]
	r=n if m==0
	x*=m
	while j<=i&&x>k
		x/=a[j]
		j+=1
	end
	r=[r,i-j+1].max
}
p r