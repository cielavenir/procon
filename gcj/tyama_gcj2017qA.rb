#!/usr/bin/ruby
(1..gets.to_i).each{|i|
	print 'Case #%i: '%i
	x,y=gets.split
	y=y.to_i
	z=(0..x.size-y).count{|j|x[j]=='-'&&(j...j+y).each{|k|x[k]=x[k].tr('-+','+-')}}
	puts x.chars.all?{|c|c==x[0]} ? z : :IMPOSSIBLE
}
