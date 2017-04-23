#!/usr/bin/ruby
x,y=$<.map{|e|
	a,b=e.split.map(&:to_i)
	(0..99).map{|i|b+i*a}
}
x&=y
puts x[0]||-1
