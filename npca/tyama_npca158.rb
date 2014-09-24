#!/usr/bin/ruby
n=gets.to_i
a=$<.map{|e|
	e.chomp.chars.map{|f|f=='Y'}
}
n.times{|i|
	if a[i][0]
		n.times{|j|a[i][j]^=true}
	end
}
puts n.times.any?{|i|n.times.any?{|j|a[0][j]!=a[i][j]}} ? "laa" : "na'am"