#!/usr/bin/ruby
gets.to_i.times{
	s=gets.chomp
	f=s=~/^hackerrank/
	g=s=~/hackerrank$/
	p f&&g ? 0 : f ? 1 : g ? 2 : -1
}