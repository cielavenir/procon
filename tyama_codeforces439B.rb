#!/usr/bin/ruby
n,x=gets.split.map(&:to_i)
r=0
gets.split.map(&:to_i).sort.each_with_index{|e,i|
	r+=[x-i,1].max*e
}
p r