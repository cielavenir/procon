#!/usr/bin/ruby
gets
s=gets.chomp
b=0
w=s.count(?.)
p ([w]+s.chars.map{|c|
	c==?. ? w-=1 : b+=1
	b+w
}).min
