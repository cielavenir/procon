#!/usr/bin/ruby
def dfs(a,d,n,s)
	if d==n then puts s;return end
	a.each{|e|dfs(a,d+1,n,s+e)}
end
dfs(a=gets.split,0,gets.to_i,'')