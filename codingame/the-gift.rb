#!/usr/bin/ruby
N,c,*B=$<.read.split.map(&:to_i)
r=[]
B.sort.each_with_index{|e,i|
	x=[e,c/(B.size-i)].min
	r<<x
	c-=x
}
puts c==0 ? r : :IMPOSSIBLE