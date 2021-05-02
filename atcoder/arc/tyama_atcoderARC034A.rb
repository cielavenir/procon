#!/usr/bin/ruby
p$<.drop(1).map{|e|
	a=e.split.map(&:to_i)
	x=a.pop*110.0/900
	a.reduce(:+)+x
}.max