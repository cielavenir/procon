#!/usr/bin/ruby
require 'bio'
n=gets.to_i
tree=Bio::Tree.new
a=[nil]+gets.split.map{|e|Bio::Tree::Node.new(e)}
a.each{|e|tree.add_node(e)}
tree.root=a[1]
2.step(n){|i|tree.add_edge(a[i/2],a[i])}
1.step(n){|i|
	print "node #{i}: key = #{a[i].name}, "
	print "parent key = #{tree.parent(a[i]).name}, " if tree.parent(a[i])
	children=tree.children(a[i])
	print "left key = #{children[0].name}, " if children[0]
	print "right key = #{children[1].name}, " if children[1]
	puts
}