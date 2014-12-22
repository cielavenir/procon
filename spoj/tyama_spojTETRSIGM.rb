#!/usr/bin/ruby
require 'uri'
gets.to_i.times{|i|
	puts "Case ##{i+1}: #{URI.parse(gets.chomp).host}"
}