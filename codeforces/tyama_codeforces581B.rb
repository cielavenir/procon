#!/usr/bin/ruby
gets
s=0
puts gets.split.map(&:to_i).reverse.map{|e|
	r=[s+1-e,0].max
	s=[s,e].max
	r
}.reverse*' '