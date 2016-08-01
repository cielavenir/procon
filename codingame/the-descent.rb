#!/usr/bin/ruby
STDOUT.sync = true
loop{
	#sx, sy = gets.split.map(&:to_i)
	mh=8.times.map{gets.to_i}

	x=mh.each_with_index.max_by{|e,i|e}[1]

	#puts sx==x ? "FIRE" : "HOLD"
	puts x
}