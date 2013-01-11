#!/usr/bin/ruby
h=Hash.new{|h,k|h[k]=[]}
gets
loop{
	x=gets.chomp.split
	case x[0]
		when 'push'; h[x[1]].push x[2]
		when 'pop'; puts h[x[1]].pop
		when 'move'; h[x[2]].push h[x[1]].pop
		when 'quit'; exit
	end
}