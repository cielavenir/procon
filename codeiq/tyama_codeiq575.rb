#!/usr/bin/ruby
(0..9999999).each{|i|
	if [10,8,2].all?{|e|
		s=i.to_s(e)
		s==s.reverse
	} then p i end
}