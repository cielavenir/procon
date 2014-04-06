#!/usr/bin/ruby
p Enumerator.new{|y|
	a=b=0
	c=1
	y<<a
	y<<b
	loop{
		y<<c
		a,b,c=b,c,(a+b+c)%10007
	}
}.take(gets.to_i).last
#.lazy.drop(gets.to_i-1).take(1).first