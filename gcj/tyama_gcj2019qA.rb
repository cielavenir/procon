#!/usr/bin/ruby
t=gets.to_i
t.times{|i|
	print 'Case #%d: '%(i+1)
	n=gets
	a=n.tr('4','2')
	puts '%s %d'%[a.chomp,n.to_i-a.to_i]
}
