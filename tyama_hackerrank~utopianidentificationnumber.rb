#!/usr/bin/ruby
gets.to_i.times{
	puts gets.chomp=~/^[a-z]{0,3}[0-9]{2,8}[A-Z]{3,}$/ ? :VALID : :INVALID
}