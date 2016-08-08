#!/usr/bin/ruby
a=b=0
gets;$<.each{|_|
	x,y=_.split.map &:to_i
	a+=1 if x>y
	b+=1 if x<y
}
puts ['Friendship is magic!^^','Chris','Mishka'][b<=>a]