#!/usr/bin/ruby
a,b=gets.to_i.times.map{
	gets.split.map(&:to_i)
}.partition{|e|
	e[0]>0
}.map{|e|
	e.sort_by{|f|f[0].abs}
}.sort_by(&:size)
p (a+b[0,a.size+1]).map(&:last).reduce(:+)