#!/usr/bin/ruby
puts $<.map{|l|
	l=~/(-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+)/
	Math.hypot($3.to_f-$1.to_f,$4.to_f-$2.to_f).to_i
}