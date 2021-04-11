#!/usr/bin/ruby
INF=1<<28
n,m=gets.to_s.split.map{|e|e.to_i}
g=n.times.map{[INF]*n}.to_a
n.times{|i|g[i][i]=0}
m.times{
	u,v,l=gets.to_s.split.map{|e|e.to_i}
	u-=1
	v-=1
	g[u][v]=g[v][u]=l
}
v=1.upto(n-1).select{|i|g[0][i]<INF}.to_a
#Warshall-Floyd
1.upto(n-1){|k|1.upto(n-1){|i|1.upto(n-1){|j|d=g[i][k]+g[k][j];g[i][j]=d if g[i][j]>d}}}
p v.combination(2).map{|(x,y)|g[0][x]+g[x][y]+g[y][0]}.select{|e|e<INF}.min||-1
# p v.each_combination(2).map{|(x,y)|g[0][x]+g[x][y]+g[y][0]}.select{|e|e<INF}.min?||-1 # Crystal
