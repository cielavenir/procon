#!/usr/bin/ruby
$h=Hash.new{|h,k|h[k]=[]}
def dfs(n)
	x,y=$h[n].map(&method(:dfs)).minmax
	(x||0)+(y||0)+1
end
(2..gets.to_i).each{|i|
	n=gets.to_i
	$h[n]<<i
}
p dfs(1)