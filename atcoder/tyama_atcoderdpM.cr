#!/usr/bin/env crystal
M=10**9+7
a=ARGF.gets_to_end.split.map &.to_i
n,k=a.shift(2)
r=[1]+[0]*k
a.each{|e|
	x=[0]
	q=0
	(1..k+1).each{|i|q=(q+r[i-1])%M;x<<q}
	r=(0..k).map{|i|(x[i+1]-x[[0,i-e].max])%M}
}
p r[k]
