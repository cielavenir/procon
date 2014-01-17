#!/usr/bin/ruby
gets.to_i.times{
	puts gets.include?('D') ? 'You shall not pass!' : 'Possible'
}