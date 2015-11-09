#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
G=Hash.new{|h,k|h[k]=[]}
$<.each{|e|
	a,b,c=e.split.map(&:to_i)
	G[b]<<[a,c/100.0]
}
r=0
(1<<(N-2)).times{|i|
	a=[0]+[1]*(N-1)
	N.times{|j|G[j].each{|x,y|a[j]*=1-y if x==0||x==N-1||i[x-1]==1}}
	r0=1
	N.times{|j|r0*=j==0||j==N-1||i[j-1]==1 ? 1-a[j] : a[j]}
	r+=r0
}
p r