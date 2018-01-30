#!/usr/bin/ruby
$memo={0=>1}
def dfs(n)
	$memo[n]||=dfs(n/3)+dfs(n/5)
end
p dfs(gets.to_i)
