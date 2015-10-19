#!/usr/bin/ruby
T=[*1..20,25]
X=gets.to_i
$memo={}
def dfs(n)
	return 0 if n>X
	return $memo[n] if $memo.has_key?(n)
	r=1
	(0...3*T.size).each{|_|
		i=_/T.size+1
		t=T[_%T.size]
		next if i==3&&t==25
		r+=dfs(n+t*i)
	}
	$memo[n]=r
end
r=0
T.each{|t|r+=dfs(t*2)}
p r%1000000009