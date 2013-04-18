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
	$tree.adjacent_nodes(v).each{|e|
		s|=dfs(e,v) if !$z[e]
	}
	$h[s]=1
	s
end
$tree = Bio::FlatFile.open(Bio::Newick,StringIO.new(gets.chomp)).next_entry.tree
$tree.nodes.select{|e|e.name}.sort_by{|e|e.name}.each_with_index{|e,i|$nodes[e]=i}
dfs($tree.root,nil)
puts $h.keys.map{|e|sprintf("%0#{$nodes.size}b",e).reverse}.select{|e|1<e.count('0')&&1<e.count('1')}*"\n"