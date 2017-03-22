#!/usr/bin/ruby
a,b=2.times.map{gets.to_i.times.map{gets.split.map(&:to_i)}.sort}
p [
	a.map{|x,y|[b[-1][0]-y,0].max}.max,
	b.map{|x,y|[a[-1][0]-y,0].max}.max,
].max
