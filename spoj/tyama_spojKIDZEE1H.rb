#!/usr/bin/ruby
gets.to_i.times{|i|
	a,b=gets.split.map(&:to_i)
	puts "Case #{i+1}:"
	1.step(b){|j|puts a.to_s*j}
}