#!/usr/bin/ruby
n=gets.to_i
p $<.map{|e|
	e.split.map(&:to_i).chunk{|f|f!=-1}.select(&:first).map{|f|
		f.last.each_cons(n).map{|g|g.reduce(:+)}.max||-1
	}.max||-1
}.max