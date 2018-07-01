#!/usr/bin/ruby
def dfs(a)
	a.map!{|e|e.is_a?(Array) ? dfs(e) : e}
	x,y=a.minmax
	raise if x!=0
	y-1
end
s=gets.tr('-',',')
$<.each{|e|s.sub!(*e.split)}
puts dfs(eval s)==0?:Yes: :No rescue puts :No
