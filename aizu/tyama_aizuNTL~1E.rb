#!/usr/bin/ruby
def egcd(x,y)
	return [x,1,0] if y==0
	g,a,b=egcd(y,x%y)
	[g,b,a-x/y*b]
end
puts egcd(*gets.split.map(&:to_i))[1,2]*' '