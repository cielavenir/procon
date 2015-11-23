#!/usr/bin/ruby
gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	puts (a.abs-b.abs).abs<=1 ? :Possible : :Impossible
}