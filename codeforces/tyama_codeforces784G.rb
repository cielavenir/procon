#!/usr/bin/ruby
prev=0
eval(*$<).to_s.bytes{|cur|
	diff1=(cur-prev)%256
	diff2=(prev-cur)%256
	if diff1<diff2
		$><<'+'*diff1+'.'
	else
		$><<'-'*diff2+'.'
	end
	prev=cur
}
puts
