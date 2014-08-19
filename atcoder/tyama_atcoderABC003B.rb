#!/usr/bin/ruby
t='atcoder'.split('')
puts $<.map{|e|e.chomp.split('')}.transpose.all?{|x,y|
	x==y || (x=='@'&&t.include?(y)) || (y=='@'&&t.include?(x))
} ? 'You can win' : 'You will lose'