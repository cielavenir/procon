#!/usr/bin/ruby
gets
m=2;c=0
a=gets.split.map(&:to_i)
if a.size==1
	p 1
	exit
end
a.each_cons(3){|e|
	if e[0]+e[1]==e[2]
		c+=1
	else
		m=[m,c+2].max
		c=0
	end
}
p [m,c+2].max