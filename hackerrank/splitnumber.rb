#!/usr/bin/ruby
gets.to_i.times{
	gets.chomp=~/^(\d+).*?(\d+).*?(\d+)$/
	puts "CountryCode=#{$1},LocalAreaCode=#{$2},Number=#{$3}"
}