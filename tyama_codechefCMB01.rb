#!/usr/bin/ruby
gets.to_i.times{
	a,b=gets.split
	p (a.reverse.to_i+b.reverse.to_i).to_s.reverse.to_i
} 