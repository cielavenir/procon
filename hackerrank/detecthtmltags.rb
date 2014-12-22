#!/usr/bin/ruby
puts gets.to_i.times.flat_map{
	a=gets.chomp.split('<')
	a.shift
	a.flat_map{|e|e.lstrip.scan(/[0-9a-z]+/).first}
}.sort.uniq*';'