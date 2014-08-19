#!/usr/bin/ruby
T=[
	'O-|-OOOO',
	'O-|O-OOO',
	'O-|OO-OO',
	'O-|OOO-O',
	'O-|OOOO-',
	'-O|-OOOO',
	'-O|O-OOO',
	'-O|OO-OO',
	'-O|OOO-O',
	'-O|OOOO-',
]
gets.chomp.reverse.chars{|e|puts T[e.to_i]}