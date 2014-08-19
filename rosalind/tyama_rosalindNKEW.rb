#!/usr/bin/ruby
require 'bio'
require 'stringio'
r=[]
while gets
newick = Bio::FlatFile.open(Bio::Newick,StringIO.new($_.chomp)).next_entry
a,b=gets.split
gets
tree = newick.tree
#tree.each_edge{|s,t,e|e.distance=1}
node1=tree.nodes.find_all{|x|x.name==a.gsub('_',' ')}[0]
node2=tree.nodes.find_all{|x|x.name==b.gsub('_',' ')}[0]
r<<tree.distance(node1,node2).to_i
end
puts r*' '