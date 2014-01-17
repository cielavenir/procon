#!/usr/bin/ruby
gets.to_i.times{|i|
	x,y,z=gets.split.map(&:to_i)
	puts "Case #{i+1}: Sum of #{x}, #{y} and #{z} is #{x+y+z}"
}