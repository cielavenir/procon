#!/usr/bin/ruby
gets.to_i.times{|i|
	print "Case ##{i+1}: "
	a=gets.chomp.each_byte.map{|b|b==45 ? 0 : 1}
	i=a.size-1
	r=0
	while i>=0
		if a[i]==0
			r+=1
			0.upto(i){|j|a[j]^=1}
		end
		i-=1
	end
	p r
}