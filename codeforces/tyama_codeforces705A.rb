#!/usr/bin/ruby
N=gets.to_i
N.times{|i|
	print i%2==0?'I hate ':'I love '
	print i<N-1?'that ':'it'+$/
}