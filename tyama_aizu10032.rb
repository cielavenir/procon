#!/usr/bin/ruby
h=[]
$<.each{|l|
	x=l.chomp.split
	case x[0]
		when 'push'; h<<x[1]
		when 'pop';  puts h.pop
		when 'quit'; exit
	end
}