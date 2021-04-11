#!/usr/bin/ruby
M=10**9+7
n,k,*a=$<.read.split.map &:to_i
r=[1]+[0]*k
a.each{|e|
	x=[q=0]
	(1..k+1).each{|i|x<<(q=q+r[i-1])%M}
	r=(0..k).map{|i|(x[i+1]-x[[0,i-e].max])%M}
}
p r[k]
