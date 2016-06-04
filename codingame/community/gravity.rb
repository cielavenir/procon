#!/usr/bin/ruby
w,h=gets.split.map(&:to_i)
puts $<.map{|e|
	e.chomp.chars
}.transpose.map{|e|
	n=e.count('.')
	['.']*n+['#']*(e.size-n)
}.transpose.map(&:join)