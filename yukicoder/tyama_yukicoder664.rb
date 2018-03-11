#!/usr/bin/ruby
N,M,K,*A=$<.read.split.map &:to_i
r=[v=K,*[0]*N]
M.times{
	a=[0]*-~N
	(1..N).each{|i|r[i]=[r[i],r[i-1]].max}
	(0..N).each{|n|n.times{|i|d,c=r[i].divmod A[i];a[n]=[a[n],c+d*A[n]].max}}
	v=[(r=a).max,v].max
}
p v
