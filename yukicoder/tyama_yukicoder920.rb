#!/usr/bin/ruby
x,y,z=gets.split.map &:to_i
x,y=y,x if x>y
if y-x>z
	p x+z
else
	p (z+x+y)/2
end
