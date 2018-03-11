#!/usr/bin/ruby
def dfs(last,first,prev,current,d,a)
	if d==a.size
		return current==first && prev==last ? 1 : 0
	else
		$memo[[prev,current,d]]||=case [prev,current,a[d]]
			when [0,0,0]; dfs(last,first,current,0,d+1,a)
			when [0,0,1]; dfs(last,first,current,1,d+1,a)
			when [0,1,1]; dfs(last,first,current,0,d+1,a)+dfs(last,first,current,1,d+1,a)
			when [0,1,0]; 0
			when [1,0,0]; dfs(last,first,current,0,d+1,a)
			when [1,0,1]; dfs(last,first,current,1,d+1,a)
			when [1,1,0]; dfs(last,first,current,1,d+1,a)
			when [1,1,1]; dfs(last,first,current,0,d+1,a)
		end
	end
end

N,*A=$<.read.split.map &:to_i
p [[0,0],[0,1],[1,0],[1,1]].reduce(0){|s,(a,b)|$memo={};s+dfs(a,b,a,b,0,A)}%(10**9+7)
