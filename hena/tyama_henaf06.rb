#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/ordf06numit/
#https://qiita.com/Nabetani/items/deda571c9451bd7d3175
STDOUT.sync=true

def dfs(n,t)
	return 1 if n==t
	return 0 if n<t
	$memo[n]||=[n/2-10,n*2/3].map{|e|
		e>0 ? dfs(e,t) : 0
	}.reduce(:+)
end
	
while gets
	$memo={}
	n,t=$_.split(',').map(&:to_i)
	p dfs(n,t)
end
