#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	a=gets.to_i
	b=gets.to_i
	a,b=b,a if a>b
	puts a==b ? a*(n-1) : n.times.map{|i|a*(n-1-i)+b*i}*' '
}