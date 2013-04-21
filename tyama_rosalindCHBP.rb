#!/usr/bin/ruby
require 'bio'
leaves=gets.chomp.split
spl=[]
while gets
	s=$_.chomp
	spl << (s=~/^1/ ? s.tr('01','10') : s)
end
spl=spl.sort_by{|e|e.count '1'}.map{|e|e.reverse.to_i(2)}
tree=Bio::Tree.new
h={}
leaves.each_with_index{|e,i|
	tree.add_node(h[1<<i]=Bio::Tree::Node.new(e))
}
spl.each{|e|
	g=h.dup
	if h.each_key{|f|
		if (e&f)==f && h.has_key?(e^f)
			tree.add_node(g[e]=Bio::Tree::Node.new)
			tree.add_edge(g[e],g.delete(e^f))
			tree.add_edge(g[e],g.delete(f))
			break
		end
	} then raise "inconsistent" end
	h=g
}
tree.add_node(tree.root=Bio::Tree::Node.new)
h.each_value{|v|tree.add_edge(tree.root,v)}
puts tree.newick(:indent=>false).gsub("'","") #lol?

__END__
a b c d e f
011000
000110

leaves=gets.chomp.split
spl=[]
while gets
	s=$_.chomp
	spl << (s=~/^1/ ? s.tr('01','10') : s)
end
spl=spl.sort_by{|e|e.count '1'}
a=Array.new(leaves.size)
r=''
spl.each{|e|
	x=[]
	e.enum_for(:chars).each_with_index{|e,i|
		if !a[i]&&e=='1'
			x<<leaves[i]
			a[i]=1
		end
	}
	r="(#{x*','}#{r=='' ? '' : ','}#{r})" if x.size>0
}
	x=[]
	spl.last.enum_for(:chars).each_with_index{|e,i|
		if !a[i]&&e=='0'
			x<<leaves[i]
			a[i]=1
		end
	}
if x.size>0
puts "(#{x*','}#{r=='' ? '' : ','}#{r});"
else
puts "#{r};"
end