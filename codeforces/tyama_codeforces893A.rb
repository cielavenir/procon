#!/usr/bin/ruby
x=3
gets
puts $<.all?{|e|
	e=e.to_i
	e!=x && x=6-x-e
} ? :YES : :NO
