#!/usr/bin/ruby
N=gets.to_i
x,y=$<.map{|e|
	e.chomp.split('')
}.transpose.map{|e|
	[e.index('X'),N-1-e.index('Y')]
}.transpose.map{|e|
	e.reduce(:+)
}
puts x>y ? 'X' : y>x ? 'Y' : 'Impossible'