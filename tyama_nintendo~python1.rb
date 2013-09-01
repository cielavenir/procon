#!/usr/bin/ruby
(2..1/0.0).each{|i|
	if i**17%3569==915
		p i
		break
	end
}