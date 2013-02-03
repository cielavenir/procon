#!/usr/bin/ruby
gets.to_i.times{
	a=gets.chomp.split
	puts a.reduce(0){|s,e|s+=sprintf("%0#{a.map(&:size).max}d",e.reverse).to_i}.to_s.reverse.to_i
}