#!/usr/bin/ruby
gets.to_i.times{
	h={}
	puts gets.to_i.times.all?{
		a,b=gets.split.map(&:to_i)
		(!h.has_key?(a)||h[a]==b) && h[a]=b
	} ? :YES : :NO
}
