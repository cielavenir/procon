#!/usr/bin/ruby
a=gets.to_i.times.map{gets.split.map(&:to_i)}
h=Hash.new(0)
a.each{|e| #not good; use bipartite graph's maximal matching.
	1.step(e[0]-1){|i|h[i*e[1]*e[2]]+=1}
	1.step(e[1]-1){|i|h[i*e[2]*e[0]]+=1}
	1.step(e[2]-1){|i|h[i*e[0]*e[1]]+=1}
}
p h.size