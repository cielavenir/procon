#!/usr/bin/ruby
def dfs(z,c)
	f=G[c].size==2?1:0
	r=[0,c]
	G[c].each{|e|
		next if e==z
		t=dfs(c,e)
		r=[r,[t[0]+f,t[1]]].max
	}
	r
end
N=gets.to_i
G=N.times.map{[]}
(N-1).times{
	a,b=gets.split.map(&:to_i)
	G[a-1]<<b-1
	G[b-1]<<a-1
}
p dfs(-1,dfs(-1,0)[1])[0]+G.count{|e|e.size==1}
