#!/usr/bin/ruby
puts gets.to_i.times.any?{
	e=gets.split.map(&:to_i)
	2400<=e[1] && e[1]<e[2]
} ? :YES : :NO