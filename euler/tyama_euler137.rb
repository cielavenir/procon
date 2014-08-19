#!/usr/bin/ruby
p Enumerator.new{|yielder|
	x,y=1,1
	loop{
		x,y=(x+5*y)/2,(x+y)/2
		yielder << (x-1)/5 if x%5==1
	}
}.take(15).last