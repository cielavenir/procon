#!/usr/bin/ruby
gets.to_i.times{
	puts gets.chomp.scan(/(010|101)/).empty? ? 'Bad' : 'Good'
}