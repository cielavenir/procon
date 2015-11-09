#!/usr/bin/env crystal
n,m=gets.not_nil!.split.map(&.to_i)
G={} of Int32 => Array(Tuple(Int32,Float64))
m.times{
	a,b,c=gets.not_nil!.split.map(&.to_i)
	G[b]||=[] of Tuple(Int32,Float64)
	G[b]<<{a,c/100.0}
}
r=0
(1<<(n-2)).times{|i|
	a=[0.0]+[1.0]*(n-1)
	n.times{|j|G[j].each{|e|a[j]*=1-e[1] if e[0]==0||e[0]==n-1||(i&(1<<e[0]-1))!=0} if G.has_key?(j)}
	r0=1
	n.times{|j|r0*=j==0||j==n-1||(i&(1<<j-1))!=0 ? 1-a[j] : a[j]}
	r+=r0
}
p r