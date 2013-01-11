#!/usr/bin/ruby
p Enumerator.new{|y|
	d=1
	loop{
		d+=2
		a,b,c=3,1,1
		a,b,c=(a+b+c)%d,a,b while a>0&&a*b*c!=1
		y<<d if a>0
	}
}.take(124).last