#!/usr/bin/ruby
gets
r=c=1
a=gets.split.map(&:to_i).each_cons(2){|x,y|
	if x<y
		c+=1
		r=[r,c].max
	else
		c=1
	end
}
p r