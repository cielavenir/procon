#!/usr/bin/ruby
_,M,*A=`dd`.split.map &:to_i
*c=(*b=(a=[z=0]*(2*M+1)))
A.each_cons(2){|l,r|
	l>r&&r+=M
	z+=r-l
	a[l+1]+=l
	a[r+1]-=l
	b[l+1]+=1
	b[r+1]-=1
}
1.upto(2*M){|i|
	a[i]+=a[i-1]
	b[i]+=b[i-1]
	c[i]=a[i]-b[i]*(i-1)
}
p z+A.map{|i|c[i]+c[i+M]}.min
