#!/usr/bin/ruby
gets
a=$<.map(&:chomp)
r=0
[a,a.map{|e|e.split('')}.transpose.map(&:join)].each{|_e|_e.each{|e|
	while e=~/a(.*?)s(.*?)u(.*?)m(.*?)i(.*?)k(.*?)a(.*?)n(.*?)a/
		p e
		r+=1
		e=e[$&.size-1..-1]
		break # ???
	end
}}
p r