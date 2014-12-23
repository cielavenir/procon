#!/usr/bin/ruby
A,B,N=gets.split.map(&:to_i)
p Enumerator.new{|y|
	a=A
	b=B
	y<<a
	loop{
		y<<b
		a,b=b,b**2+a
	}
}.take(N).last