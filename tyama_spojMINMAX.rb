#!/usr/bin/ruby
gets.to_i.times{|t|
	puts "Group ##{t+1}: #{gets.split.map(&:to_i)[1..-1].max}"
}