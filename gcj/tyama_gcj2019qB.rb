#!/usr/bin/ruby
t=gets.to_i
t.times{|i|
	print 'Case #%d: '%(i+1)
	gets
	puts gets.tr('ES','SE')
}
