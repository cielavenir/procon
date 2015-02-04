#!/usr/bin/env ruby
require 'tsort'
class Hash
	include TSort
	alias tsort_each_node each_key
	def tsort_each_child(node, &block)
		fetch(node).each(&block)
	end
end
A=gets.to_i.times.map{gets.chomp.chars.to_a}
h={}
A.combination(2){|x,y|
	if [x.size,y.size].min.times{|i|
		if x[i]!=y[i]
			h[x[i]]||=[]
			h[y[i]]||=[]
			h[y[i]]<<x[i]
			break
		end
	} && x.size>y.size
		puts :Impossible
		exit
	end
}
r=([*'a'..'z']-h.keys+h.tsort)*'' rescue 'Impossible'
puts r