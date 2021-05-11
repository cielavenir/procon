#!/usr/bin/env ruby
def dfs(g,z,c)
	f=1
	r=[0,c]
	g[c].each{|e|
		next if e==z
		t=dfs(g,c,e)
		r=[r,[t[0]+f,t[1]]].max
	}
	r
end
def diameter(g)
	dfs(g,-1,dfs(g,-1,0)[1])[0]
end
n=gets.to_s.to_i
g=n.times.map{[0]*0}.to_a
(n-1).times{
	a,b=gets.to_s.split.map{|e|e.to_i}
	g[a-1]<<b-1
	g[b-1]<<a-1
}
p 2*~-n-diameter(g)

