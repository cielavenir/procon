#!/usr/bin/ruby
gets
r=0
n=0
gets.split.each{|e|
	n+=e.to_i
	if n<0
		r+=-n
		n=0
	end
}
p r