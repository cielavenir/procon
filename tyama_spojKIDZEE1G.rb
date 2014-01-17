#!/usr/bin/ruby
gets.to_i.times{|i|
	a,b=gets.split.map(&:to_i)
	puts "Case #{i+1}: #{(b/a).times.map{|j|(j+1)*a}*' '}"
}