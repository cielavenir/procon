#!/usr/bin/ruby
r=f=0
gets.to_i.times.map{x,y=gets.split.map(&:to_i);[x,x+y]}.sort_by{|x,y|[y,x]}.each{|x,y|
	if x>=f
		r+=1
		f=y
	end
}
p r