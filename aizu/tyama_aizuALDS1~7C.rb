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
	next if x==[-1,-1]
	x.each{|e|
		$tree.add_edge($a[p],e!=-1 ? $a[e] : Bio::Tree::Node.new(:dummy))
		roots[e]=nil if e!=-1
	}
}
$tree.root=$a[roots.find{|e|e}]
def preorder(node)
	return if node.name==:dummy
	print " #{node.name}"
	$tree.children(node).each{|e|preorder(e)}
end
def inorder(node)
	return if node.name==:dummy
	children=$tree.children(node)
	inorder(children[0]) if children[0]
	print " #{node.name}"
	inorder(children[1]) if children[1]
end
def postorder(node)
	return if node.name==:dummy
	$tree.children(node).each{|e|postorder(e)}
	print " #{node.name}"
end
puts 'Preorder'
preorder($tree.root);puts
puts 'Inorder'
inorder($tree.root);puts
puts 'Postorder'
postorder($tree.root);puts