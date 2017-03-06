#!/usr/bin/ruby
gets;t={};r=0;gets.split.each{|e|
	if t.has_key?(e)
		t.delete(e)
	else
		t[e]=1
		r=[r,t.size].max
	end
};p r
