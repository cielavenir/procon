#!/usr/bin/ruby
k=gets.to_i
(0..30).each{|a|
	(0..30-a).each{|b|
		if 2**a*b*~-b/2==k
			p a+b
			puts [*[0]*a,*[1]*b]*' '
			exit
		end
	}
}
