#!/usr/bin/ruby
p Enumerator.new{|y|
	a=b=1
	y<<a
	loop{
		y<<b
		a,b=b,a+b
	}
}.take(gets.to_i+1).last