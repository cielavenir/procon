#!/usr/bin/ruby
s=gets.chomp
a=gets.split.map(&:to_f)
puts a.map{|e|
	s.chars.map{|f|
		Math.log10((f=='G'||f=='C'?e:(1-e))/2)
	}.reduce(:+)
}.map{|e|sprintf('%.3f',e)}.join(' ')