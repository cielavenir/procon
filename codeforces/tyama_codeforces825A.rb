#!/usr/bin/ruby
gets
prev='0'
x=0
gets.chomp.chars{|c|
	if c=='0'
		if prev=='0'
			print 0
		else
			print x
			x=0
		end
	else
		x+=1
	end
	prev=c
}
print x
