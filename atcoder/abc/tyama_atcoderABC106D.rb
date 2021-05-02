#!/usr/bin/ruby
n,m,q=gets.split.map &:to_i
a=(n+1).times.map{[0]*(n+1)}
m.times{
	l,r=gets.split.map &:to_i
	a[l][r]+=1
}
n.times{|y|(n+1).times{|x|a[y+1][x]+=a[y][x]}}
(n+1).times{|y|n.times{|x|a[y][x+1]+=a[y][x]}}
q.times{
	l,r=gets.split.map &:to_i
	p a[l-1][l-1]-a[l-1][r]-a[r][l-1]+a[r][r]
}
