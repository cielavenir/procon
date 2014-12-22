#!/usr/bin/ruby
gets.to_i.times{|i|
	puts "Case #{i+1}: #{gets.split.map(&:to_i).sort*' '}"
}