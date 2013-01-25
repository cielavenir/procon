#!/usr/bin/ruby
require 'bio'
require 'stringio'
$h={}
$nodes={}
$z={}
def dfs(v,p)
	$z[v]=1
	s=0
	s|=1<<$nodes[v] if $nodes[v]
	$tree.descendents(v).each{|e|
		if !$z[e]
			s|=dfs(e,v)
		end
	}
	$h[s]=1
	s
end
$tree = Bio::FlatFile.open(Bio::Newick,StringIO.new(gets.chomp)).next_entry.tree
$tree.nodes.select{|e|e.name}.sort_by{|e|e.name}.each_with_index{|e,i|$nodes[e]=i}
dfs($tree.root,nil)
puts $h.keys.map{|e|sprintf("%0#{$nodes.size.to_s}b",e).reverse}.select{|e|1<e.scan(/0/).size&&e.scan(/0/).size<$nodes.size-1}*"\n"