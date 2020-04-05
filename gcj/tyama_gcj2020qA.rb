#!/usr/bin/ruby
t=gets.to_i
t.times{|i|
	print 'Case #%d: '%(i+1)
	n=gets.to_i
	a=n.times.map{gets.split.map(&:to_i)}
	puts '%d %d %d'%[
		n.times.map{|i|a[i][i]}.reduce(:+),
		a.count{|e|e!=e.uniq},
		a.transpose.count{|e|e!=e.uniq},
	]
}
