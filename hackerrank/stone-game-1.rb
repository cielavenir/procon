#!/usr/bin/ruby
gets.to_i.times{
	puts [0,1].include?(gets.to_i%7) ? :Second : :First
}