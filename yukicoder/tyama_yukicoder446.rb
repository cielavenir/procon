#!/usr/bin/ruby
puts $<.all?{|_|
	e=_.chomp
	n=e.to_i
	0<=n&&n<=12345 && n.to_s==e
} ? :OK : :NG
