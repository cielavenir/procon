#!/usr/bin/ruby
r=0
gets;gets.split.map(&:to_i).each{|e|
	break if r>e
	r^=e%2
}
puts [:YES,:NO][r]
