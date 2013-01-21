#!/usr/bin/ruby
a=46341.times.map{|e|e**2}
m={}
a.each{|e|m[e]=1}
gets.to_i.times{
	n=gets.to_i
	p a.take_while{|e|n/2>=e}.select{|e|m[n-e]}.count
}