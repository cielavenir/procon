#!/usr/bin/env ruby
n=gets.to_i
a=gets.split.map(&:to_i)
p 1.step(n-2).map{|i|
	b=a[0,i]+a[i+1..-1]
	b.each_cons(2).map{|x,y|y-x}.max
}.min