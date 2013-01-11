#!/usr/bin/ruby
h=[]
loop{
	x=gets.chomp.split
	case x[0]
		when 'push'; h.push x[1]
		when 'pop'; puts h.pop
		when 'quit'; exit
	end
}