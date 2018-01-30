#!/usr/bin/ruby
gets;puts ([[0,0,0]]+$<.map{|e|e.split.map &:to_i}).each_cons(2).all?{|e,f|
	t=f[0]-e[0];x=f[1]-e[1];y=f[2]-e[2]
	x+y<=t && (t-x-y)%2<1
} ? :Yes : :No
