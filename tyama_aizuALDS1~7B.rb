#!/usr/bin/ruby
require 'bio'
n=gets.to_i
$tree=Bio::Tree.new
$a=n.times.map{|i|Bio::Tree::Node.new(i)}
$a.each{|e|$tree.add_node(e)}
roots=n.times.to_a
n.times{
	x=gets.split.map(&:to_i)
	p=x.shift
	x.each{|e|
		next if e==-1
		$tree.add_edge($a[p],$a[e])
		roots.delete(e)
	}
}
$tree.root=$a[roots[0]]
$depth=Array.new(n)
$height=Array.new(n,0)
def dfs(h,i)
	$height[i]=[$height[i],h].max
	if $tree.parent($a[i])
		$depth[i]=1+dfs(h+1,$tree.parent($a[i]).name)
	else
		$depth[i]=0
	end
end
n.times.map{|i|dfs(0,i)}
n.times{|i|
	children=$tree.children($a[i]).map(&:name)
	print "node #{i}: parent = "
	if $tree.parent($a[i])
		print $tree.parent($a[i]).name
	else
		print -1
	end
	print ", sibling = "
	if $tree.parent($a[i])
		n=($tree.children($tree.parent($a[i])).map(&:name)-[i])[0]
		print n ? n : -1
	else
		print -1
	end
	print ", degree = #{children.size}, depth = #{$depth[i]}, height = #{$height[i]}"
	puts ", #{$a[i]==$tree.root ? 'root' : children.size==0 ? 'leaf' : 'internal node'}"
}