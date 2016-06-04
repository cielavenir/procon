#!/usr/bin/ruby
gets.to_i.times{
	gets
	puts gets.split.map(&:to_i).reduce(:^)==0 ? :Second : :First
}