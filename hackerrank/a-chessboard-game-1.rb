#!/usr/bin/ruby
gets.to_i.times{
	puts gets.split.map(&:to_i).any?{|e|[0,3].include?(e%4)} ? :First : :Second
}