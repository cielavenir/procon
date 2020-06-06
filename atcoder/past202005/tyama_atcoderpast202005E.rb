#!/usr/bin/ruby
n,m,q=gets.split.map &:to_i
G=Hash.new{|h,k|h[k]=[]}
m.times{
	u,v=gets.split.map{|e|e.to_i-1}
	G[u]<<v
	G[v]<<u
}
c=gets.split.map &:to_i
q.times{
	z,x,y=gets.split.map &:to_i
	if z==1
		x-=1
		p c[x]
		G[x].each{|e|c[e]=c[x]}
	elsif z==2
		x-=1
		p c[x]
		c[x]=y
	end
}
