#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
x=n.times.map{[99999]*n}
n.times{|i|x[i][i]=0}
m.times{
	a,b=gets.split.map(&:to_i)
	x[a-1][b-1]=x[b-1][a-1]=1
}
n.times{|k|n.times{|i|n.times{|j|
	x[i][j]=[x[i][j],x[i][k]+x[k][j]].min
}}}
n.times{|i|p x[i].count(2)}