#!/usr/bin/ruby
gets
m=$<.map{|e|e.chomp.split.map(&:to_i)}
p [m,m.transpose].reduce(0){|r,m|
	c=0
	m.each{|e|
		s=e.count 1
		l=e.size
		if s==1
			c+=l-1
		elsif s>1
			x=e.index 1
			y=e.reverse.index 1
			c+=x+2*(l-(x+y)-s)+y
		end
	}
	r+c
}
