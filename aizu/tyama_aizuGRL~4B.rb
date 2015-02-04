#!/usr/bin/ruby
require 'tsort'
class Hash
	include TSort
	alias tsort_each_node each_key
	def tsort_each_child(node, &block)
		fetch(node).each(&block)
	end
end
V,E=gets.split.map(&:to_i)
h={}
E.times{
	k,v=gets.split.map(&:to_i)
	h[k]||=[]
	h[v]||=[]
	h[v]<<k
}
puts [*0...V]-h.keys
puts h.tsort