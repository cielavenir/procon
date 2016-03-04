#!/usr/bin/ruby
r,c,n,k=gets.split.map(&:to_i)
m=(r+1).times.map{[0]*(c+1)}
n.times{
	a,b=gets.split.map(&:to_i)
	m[a][b]=1
}
(r+1).times{|i|c.times{|j|m[i][j+1]+=m[i][j]}}
r.times{|i|(c+1).times{|j|m[i+1][j]+=m[i][j]}}
x=0
r.times{|i0|c.times{|j0|(i0+1).step(r){|i1|(j0+1).step(c){|j1|
	x+=1 if k<=m[i0][j0]-m[i0][j1]-m[i1][j0]+m[i1][j1]
}}}}
p x