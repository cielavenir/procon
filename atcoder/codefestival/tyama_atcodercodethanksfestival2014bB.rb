#!/usr/bin/ruby
class Fixnum
	#def -(other) self*other end
	alias - *
end
a,b,c=$<.map(&:to_i)
p [a+b+c,a+b-c,a-b+c,a-b-c].max