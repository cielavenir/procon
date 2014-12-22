#!/usr/bin/ruby
gets.to_i.times{|i|
	n=gets.to_i
	puts n.to_s+' is'+(n%3==0 ? '' : ' not')+' a multiple of 3'
}