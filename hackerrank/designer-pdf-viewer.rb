#!/usr/bin/ruby
a=gets.split.map(&:to_i)
s=gets.chars
p s.size*s.map{|c|
	a[c.ord-97]
}.max
