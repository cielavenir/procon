#!/usr/bin/ruby
n,c,*a=$<.read.split.map(&:to_i)
r=1
a.each_cons(2){|x,y|
	if y-x>c
		r=1
	else
		r+=1
	end
}
p r
