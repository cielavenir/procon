#!/usr/bin/ruby
$memo={}
def dfs(v,d,r)
	return 0 if d==v.size
	$memo[[d,r]]||=(0..[r,3].min).reduce(1<<30){|s,i|
		[s,dfs(v,d+1,r-i)+v[d][i]].min
	}
end
n,k=gets.split.map(&:to_i)
v=$<.map{|e|e.split.map(&:to_i)+[1]}
p dfs(v,0,k)/n.to_f
