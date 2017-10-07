#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{gets.chomp}
m=a.sort
a.each{|e|
	idx1=(0...n).bsearch{|i|m[i]>=e}||n
	idx2=(0...n).bsearch{|i|m[i]>e}||n
	p idx1*3+(idx2-idx1-1)
}
