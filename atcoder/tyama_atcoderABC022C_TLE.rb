#!/usr/bin/ruby
INF=1<<30
N,M=gets.split.map(&:to_i)
G=N.times.map{[INF]*N}
N.times{|i|G[i][i]=0}
M.times{
	u,v,l=gets.split.map(&:to_i)
	u-=1
	v-=1
	G[u][v]=G[v][u]=l
}
v=[]
1.step(N-1){|i|v<<i if G[0][i]<INF}
if v.size<2
	p -1
	exit
end
#Warshall-Floyd
1.step(N-1){|k|1.step(N-1){|i|1.step(N-1){|j|G[i][j]=[G[i][j],G[i][k]+G[k][j]].min}}}
p v.combination(2).map{|x,y|G[0][x]+G[x][y]+G[y][0]}.select{|e|e<INF}.min||-1