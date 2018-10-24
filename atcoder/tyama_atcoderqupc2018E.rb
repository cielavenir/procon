#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
m=Hash.new 0;m[s=0]=1
l=[0]*-~n;r=[0]*-~n
n.times{|i|
	s+=a[i]
	l[i+1]=l[i]+m[s]
	m[s]+=1
}
m=Hash.new 0;m[s=0]=1
(n-1).downto(0){|i|
	s+=a[i]
	r[i]=r[i+1]+m[s]
	m[s]+=1
}
p n.times.map{|i|l[i]+r[i+1]}.min
