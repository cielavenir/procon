#!/usr/bin/ruby
def dfs(a,d,n,s)
	return if d==n
	a.each{|e|puts s+e;dfs(a,d+1,n,s+e)}
end
dfs(a=gets.split,0,gets.to_i,'')