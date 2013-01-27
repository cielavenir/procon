#!/usr/bin/ruby
gets.to_i.times{
	a=gets.chomp.split
	puts a.map{|e|sprintf("%0#{a.map(&:size).max}d",e.reverse).to_i}.reduce(:+).to_s.reverse.to_i
}