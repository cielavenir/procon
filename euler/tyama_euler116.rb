#!/usr/bin/ruby
p [2,3,4].map{|n|
	a=[1]*n
	n.step(50){|i|a<<a[i-n]+a[i-1]}
	a.last-1
}.reduce(:+)