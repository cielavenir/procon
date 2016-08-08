#!/usr/bin/ruby
gets.to_i.times{|i|
	print "Case ##{i+1}: "
	a,b=gets.split
	s=r=0
	b.chars.map(&:to_i).each_with_index{|e,i|
		if i>s
			r+=i-s
			s=i
		end
		s+=e
	}
	p r
}