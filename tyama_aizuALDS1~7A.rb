#!/usr/bin/ruby
#It seems constraint is wrong (n<=100000)
require 'bio'
n=gets.to_i
tree=Bio::Tree.new
a=n.times.map{|i|Bio::Tree::Node.new(i)}
a.each{|e|tree.add_node(e)}
roots=n.times.to_a
n.times{
	x=gets.split.map(&:to_i)
	p=x.shift
	x.shift
	x.each{|e|
		tree.add_edge(a[p],a[e])
		roots.delete(e)
	}
}
tree.root=a[roots[0]]
n.times{|i|
	children=tree.children(a[i]).map(&:name)
	print "node #{i}: parent = "
	if tree.parent(a[i])
		print tree.parent(a[i]).name
	else
		print -1
	end
	print ", depth = "
	node=a[i]
	d=0
	while node=tree.parent(node) do d+=1 end
	print d
	print ", #{a[i]==tree.root ? 'root' : children.size==0 ? 'leaf' : 'internal node'}, ["
	print tree.children(a[i]).map(&:name)*', '
	puts "]"
}