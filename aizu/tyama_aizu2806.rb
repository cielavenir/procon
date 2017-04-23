#!/usr/bin/ruby
n,m,*a=$<.read.split.map(&:to_i)
a+=a
r=0
c=0
(n.lcm(m)/m).times{
	mi,ma=a[c,m].minmax
	r+=ma-mi
	c=(c+m)%n
}
p r
