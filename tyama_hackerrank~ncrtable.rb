#!/usr/bin/ruby
a=[[1,1]]
1.step(999){|i|a[i]=[1]+a[i-1].each_cons(2).map{|x,y|x+y}+[1]}
gets.to_i.times{
	puts a[gets.to_i-1].map{|e|e%1000000000}*' '
}