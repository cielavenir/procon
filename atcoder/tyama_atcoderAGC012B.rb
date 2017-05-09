#!/usr/bin/ruby
def dfs(v,d,c)
	$c[v]=c if !$c[v]
	return if $m[v]>=d||d==0
	$m[v]=d
	$h[v].each{|e|dfs(e,d-1,c)}
end
n,m=gets.split.map &:to_i
$c=[nil]*n
$m=[0]*n
$h=Hash.new{|h,k|h[k]=[]}
m.times{
	a,b=gets.split.map &:to_i
	$h[a-1]<<b-1
	$h[b-1]<<a-1
}
gets.to_i.times.map{
	gets.split.map &:to_i
}.reverse_each{|v,d,c|
	dfs(v-1,d,c)
}
puts $c.map{|e|e||0}
