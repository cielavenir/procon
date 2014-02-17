#!/usr/bin/ruby
a=[*1..6]
N=gets.to_i
(N%30).times{|i|
	a[i%5],a[i%5+1]=a[i%5+1],a[i%5]
}
puts a*''