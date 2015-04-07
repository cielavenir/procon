#!/usr/bin/ruby

def dfs(d,cur,prev,lst)
	if i=lst[cur]
		l=d-i
		print 1+l/N,' ',N-l%2,$/
		exit
	end
	lst[cur]=d
	$h[cur].each{|e|dfs(d+1,e,cur,lst) if e!=prev}
	lst.delete(cur)
end

$h=Hash.new{|h,k|h[k]=[]}
N=gets.to_i
N.times{
	a,b=gets.split.map(&:to_i)
	$h[a]<<b
	$h[b]<<a
}
dfs(1,1,-1,{})