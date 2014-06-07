#!/usr/bin/ruby
gets
puts gets.split.map{|e|
	n=e.to_i
	(0..6).find{|i|[1,3].include? (n-i)%6}
}.reduce(:+)