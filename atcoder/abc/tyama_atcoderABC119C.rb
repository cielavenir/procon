#!/usr/bin/ruby
N,A,B,C,*L=`dd`.split.map &:to_i
def dfs(cur, a, b, c)
	if cur==N
		return [a,b,c].min>0 ? (a-A).abs+(b-B).abs+(c-C).abs-30 : 1<<30
	end
	[
		dfs(cur+1, a, b, c),
		dfs(cur+1, a+L[cur], b, c) + 10,
		dfs(cur+1, a, b+L[cur], c) + 10,
		dfs(cur+1, a, b, c+L[cur]) + 10,
	].min
end
p dfs 0,0,0,0
