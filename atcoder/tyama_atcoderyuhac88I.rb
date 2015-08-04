#!/usr/bin/ruby
N=gets.to_i
M=N.times.map{gets.chomp}
(N-1).times{|h|
	N.times{|w|
		print M[h+1][w] if 'monica'.include?(M[h][w])
	}
}
puts