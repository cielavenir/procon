#!/usr/bin/ruby
n,y=gets.split.map &:to_i
(0..n).each{|i|(0..n-i).each{|j|
	k=n-i-j
	if i*1000+j*5000+k*10000==y
		puts [k,j,i]*' '
		exit
	end
}}
puts '-1 -1 -1'
