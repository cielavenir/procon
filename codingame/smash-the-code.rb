#!/usr/bin/ruby
STDOUT.sync = true

loop{
	drops=8.times.map{gets.split.map(&:to_i)}
	mine=12.times.map{gets.chomp.chars.to_a}
	opponent=12.times.map{gets.chomp.chars.to_a}

	#puts 0 # "x": the column in which to drop your blocks
	#puts drops[0][1]
	#STDERR.puts mine.transpose.inspect
	puts [0,5,1,4,2,3].find{|i|mine.transpose[i].count('.')>=2}
}