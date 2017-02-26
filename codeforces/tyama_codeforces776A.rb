#!/usr/bin/ruby
a,b=gets.split
puts [a,b]*' '
gets
$<.each{|e|
	x,y=e.split
	if a==x
		a=y
	elsif b==x
		b=y
	end
	puts [a,b]*' '
}
