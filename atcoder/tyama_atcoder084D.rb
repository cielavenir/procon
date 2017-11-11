#!/usr/bin/ruby
D=[1<<99]*K=gets.to_i
q=[D[1]=1]
while n=q.shift
	[[n*10%K,0,:unshift],[(n+1)%K,1,:<<]].each{|e,d,m|
		(D[e]>x=D[n]+d)&&(D[e]=x;q.send(m,e))
	}
end
p D[0]
