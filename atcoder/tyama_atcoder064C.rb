#!/usr/bin/ruby
n,x,*a=`dd`.split.map &:to_i
r=0
(n-1).times{|i|
	k=[a[i]+a[i+1]-x,0].max
	l=[a[i+1],k].min
	r+=k
	a[i+1]-=l
}
p r
