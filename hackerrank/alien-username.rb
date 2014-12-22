#!/usr/bin/ruby
gets.to_i.times{
	puts gets.chomp=~/^[_\.][0-9]+[a-zA-Z]*_?$/ ? :VALID : :INVALID
}