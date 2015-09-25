#!/usr/bin/ruby
r=m=1
gets
gets.split.map(&:to_i).each_cons(2){|x,y|
	m=x>y ? 1 : m+1
	r=[r,m].max
}
p r