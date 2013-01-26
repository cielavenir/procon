#!/usr/bin/ruby
require 'bio'
spl=[]
while gets
	s=$_.chomp
	spl << [(s=~/^1/ ? s.tr('01','10') : s),s]
end
spl=spl.sort_by{|e|e[0].scan(/1/).size}
ret=spl.transpose[1]
spl=spl.transpose[0]
len=spl[0].length
spl=spl.map{|e|e.reverse.to_i(2)}

[*0..spl.size-1].combination(spl.size-1){|indexes|
	spl0=indexes.map{|i|spl[i]}
	tree=Bio::Tree.new
	h={}
	len.times{|i|
		tree.add_node(h[1<<i]=Bio::Tree::Node.new)
	}
	begin
	spl0.each{|e|
		g=h.dup
		if h.each_key{|f|
			if (e&f)==f && h.has_key?(e^f)
				tree.add_node(g[e]=Bio::Tree::Node.new)
				tree.add_edge(g[e],g.delete(e^f))
				tree.add_edge(g[e],g.delete(f))
				break
			end
		} then raise end
		h=g
	}
	rescue; next end
	puts indexes.map{|i|ret[i]}*"\n"
	exit
}