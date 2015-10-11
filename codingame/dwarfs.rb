#!/usr/bin/ruby
$memo={}
$tree=Hash.new{|h,k|h[k]=[]}
def dfs(n)
	$memo[n]||=($tree[n].map{|e|dfs(e)}.max||0) + 1
end

top={}
gets.to_i.times{
	x,y=gets.split.map(&:to_i)
	top[x]=1
	$tree[x]<<y
}
p top.map{|k,v|dfs(k)}.max