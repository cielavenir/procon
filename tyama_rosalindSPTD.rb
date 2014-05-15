#!/usr/bin/ruby
require 'bio'
require 'stringio'
def dfs(t,n,h)
	$z[n]=1
	s=0
	s^=$leaf[n.name.tr(' ','_')] if n.name
	t.adjacent_nodes(n).each{|e|
		s^=dfs(t,e,h) if !$z[e]
	}
	h[s]=1
	s
end
leaves=gets.split
$leaf={}
leaves.each_with_index{|e,i|$leaf[e]=1<<i}
t1=Bio::FlatFile.open(Bio::Newick,StringIO.new(gets.chomp)).next_entry.tree
t2=Bio::FlatFile.open(Bio::Newick,StringIO.new(gets.chomp)).next_entry.tree
h1={}
h2={}
$z={}
dfs(t1,t1.root,h1)
$z={}
dfs(t2,t2.root,h2)
puts (h1.keys|h2.keys).size-(h1.keys&h2.keys).size