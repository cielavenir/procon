#!/usr/bin/ruby
p Enumerator.new{|y|
	a=[1,1]
	y<<1;y<<1
	2.upto(1/0.0){|i|
		a<<a[i-1]+a[i-2]
		y<<a.last
	}
}.take(gets.to_i+1).last