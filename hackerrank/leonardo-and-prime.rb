#!/usr/bin/ruby
a=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59]
gets.to_i.times{
	n=gets.to_i
	r=1
	p a.size.times.find{|i|n<r*=a[i]}
}
