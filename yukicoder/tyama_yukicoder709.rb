#!/usr/bin/ruby
(n,m),*a=$<.map{|e|e.split.map &:to_i}
deg=[r=0]*n
ma=[-1]*m
people=m.times.map{[]}
n.times{|i|
	m.times{|j|
		if ma[j]<a[i][j]
			people[j].each{|e|
				deg[e]-=1
				r-=1 if deg[e]==0
			}
			people[j]=[]
			ma[j]=a[i][j]
		end
		if ma[j]==a[i][j]
			deg[i]+=1
			r+=1 if deg[i]==1
			people[j]<<i
		end
	}
	p r
}
