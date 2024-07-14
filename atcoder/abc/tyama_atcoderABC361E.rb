#!/usr/bin/ruby
def dfs(z,c)
	r=[0,c]
	G[c].each{|e,f|
		next if e==z
		t=dfs(c,e)
		r=[r,[t[0]+f,t[1]]].max
	}
	r
end
def diameter
	dfs(-1,dfs(-1,0)[1])[0]
end
N=gets.to_i
G=N.times.map{[]}
s=0
(N-1).times{
	a,b,c=gets.split.map(&:to_i)
	G[a-1]<<[b-1,c]
	G[b-1]<<[a-1,c]
	s+=c
}
p 2*s-diameter
