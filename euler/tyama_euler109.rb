#!/usr/bin/ruby
T=[*1..20,25]
def dfs(c,d,n)
	return 0 if n>=100
	return 1 if d==0
	r=1
	(c...3*T.size).each{|_|
		i=_/T.size+1
		t=T[_%T.size]
		next if i==3&&t==25
		r+=dfs(_,d-1,n+t*i)
	}
	r
end
r=0
T.each{|t|r+=dfs(0,2,t*2)}
p r