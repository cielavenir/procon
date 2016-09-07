#!/usr/bin/ruby
$memo={1=>0}
def dfs(n)
	$memo[n] ||= n%2==0 ? dfs(n/2)+n : dfs(n/2*3+2)+n+1
end
p dfs gets.to_i