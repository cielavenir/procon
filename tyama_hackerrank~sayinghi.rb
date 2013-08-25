#!/usr/bin/ruby
gets.to_i.times{
	s=gets.chomp
	puts s if s=~/^[hH][iI] [^dD]/
}