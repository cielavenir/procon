#!/usr/bin/ruby
gets.to_i.times{
	a=gets.to_i.times.map{gets.chomp.chars.sort}.transpose
	puts a.all?{|e|e.sort==e} ? :YES : :NO
}