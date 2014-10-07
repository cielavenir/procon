#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{gets.split}
perm=gets.split.map{|e|e.to_i-1}
a=perm.map{|e|a[e]}
cur=a[0].min
puts (1...n).all?{|i|
	cur=a[i].select{|e|e>=cur}.min
} ? :YES : :NO