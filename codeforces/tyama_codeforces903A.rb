#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	puts n>=12||[3,6,7,9,10].include?(n) ? :YES : :NO
}
