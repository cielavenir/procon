#!/usr/bin/ruby
s=gets.chomp
r=0
(1<<(s.size-1)).times{|i|
	x=0
	s.size.times{|j|
		x=x*10+s[j].to_i
		if i[j]==1
			r+=x
			x=0
		end
	}
	r+=x
}
p r