#!/usr/bin/ruby
gets.to_i.times{
	puts gets.chomp=~/^[A-Z]{5}\d{4}[A-Z]$/ ? 'YES' : 'NO'
}