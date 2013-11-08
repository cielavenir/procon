#!/usr/bin/ruby
puts gets.to_i.times.map{
	a=gets.chomp.split('<')
	a.shift
	a.map{|e|e.lstrip.scan(/[0-9a-z]+/).first}
}.flatten.sort.uniq*';'