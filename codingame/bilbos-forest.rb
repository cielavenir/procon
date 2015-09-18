#!/usr/bin/ruby
T=' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
prev=0
gets.chomp.chars{|c|
	cur=T.index(c)
	diff1=(cur-prev)%T.size
	diff2=(prev-cur)%T.size
	if diff1<diff2
		$><<'+'*diff1+'.'
	else
		$><<'-'*diff2+'.'
	end
	prev=cur
}
puts