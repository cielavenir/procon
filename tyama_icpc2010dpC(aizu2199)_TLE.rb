#!/usr/bin/ruby
INF=1<<30
while(n,m=gets.split.map(&:to_i))!=[0,0]
	c=m.times.map{gets.to_i}
	prev=[INF]*256
	prev[128]=0
	cur=[INF]*256
	n.times{
		x=gets.to_i
		256.times{|j|cur[j]=INF}
		256.times{|j|
			if prev[j]<INF
				m.times{|k|
					t=[255,[0,j+c[k]].max].min
					y=prev[j]+(x-t)**2
					cur[t]=[cur[t],y].min
				}
			end
		}
		prev,cur=cur,prev
	}
	p prev.min
end