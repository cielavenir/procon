#!/usr/bin/ruby
w,h=gets.split.map(&:to_i)
c=gets.to_i
m=$<.map{|e|
	e.chomp.chars
}
c.times{
	m=m.reverse.map{|e|
		n=e.count('.')
		['.']*n+['#']*(e.size-n)
	}.transpose.map(&:reverse)
}
puts m.map(&:join)
