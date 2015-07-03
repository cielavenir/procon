#!/usr/bin/ruby
N=gets.to_i
N.times{|i|
	puts ' '*(N-1-i)+'#'*(i+1)
}