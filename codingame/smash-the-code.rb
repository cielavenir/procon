#!/usr/bin/ruby
STDOUT.sync = true

loop{
	drops=8.times.map{gets.split.map(&:to_i)}
	score=gets.to_i
	mine=12.times.map{gets.chomp.chars.to_a}
	opponent_score=gets.to_i
	opponent=12.times.map{gets.chomp.chars.to_a}

	#puts 0 # "x": the column in which to drop your blocks
	#puts drops[0][1]
	#STDERR.puts mine.transpose.inspect
	cnt=drops.size.times.find{|i|drops[0][0]!=drops[i][0]}-1
	a=drops[0][0]<4 ? [5,4,3,2,1,0] : [0,1,2,3,4,5]
	idxes=a.select{|i|mine.transpose[i].count('.')>=2}
	puts '%d 1'%[idxes[cnt].to_i]
}