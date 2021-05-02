#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
b=a.pop n
r=1
n.times{|i|
	x=i<1||a[i-1]<a[i]?a[i]:0
	y=i>n-2||b[i]>b[i+1]?b[i]:0
	r=x+y==0?r*[a[i],b[i]].min%(10**9+7):y>a[i]||x>b[i]?0:r
}
p r
