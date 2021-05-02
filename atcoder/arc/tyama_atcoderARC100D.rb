#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
v=[0]
a.each{|e|v<<v[-1]+e}
r=[0,Float::INFINITY]
(2..n-2).each{|maxc|
	r0=r1=[0,Float::INFINITY]
	v0=-~v[maxc]/2
	maxb=(1...maxc).bsearch{|maxb|v0<=v[maxb]}||maxc
	[maxb,maxb-1].each{|maxb|
		r0=[r0,[v[maxb],v[maxc]-v[maxb]].minmax].min_by{|x,y|y-x}
	}
	v1=-~(v[n]-v[maxc])/2
	maxd=(1...n).bsearch{|maxd|v1<=v[maxd]-v[maxc]}||n
	[maxd,maxd-1].each{|maxd|
		r1=[r1,[v[maxd]-v[maxc],v[n]-v[maxd]].minmax].min_by{|x,y|y-x}
	}
	r=[r,(r0+r1).minmax].min_by{|x,y|y-x}
}
p r[1]-r[0]
