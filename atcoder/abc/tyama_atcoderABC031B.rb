#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
gets.to_i.times{
	n=gets.to_i
	if n<a
		p a-n
	elsif b<n
		p -1
	else
		p 0
	end
}