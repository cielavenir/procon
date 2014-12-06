#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i)
if a+b==c
	puts a-b==c ? '?' : '+'
else
	puts a-b==c ? '-' : '!'
end