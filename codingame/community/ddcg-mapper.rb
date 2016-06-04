#!/usr/bin/ruby
l=gets.to_i
r=[0]*l
n=gets.to_i
$<.each{|e|
	x,y=e.split
	x=x.chars.each_with_index.map{|f,i|(f=='X' ? 1 : 0)<<i}.reduce(:+)
	y=y.to_i
	y.step(l,y){|i|
		r[i-1]|=x
	}
}
puts r.reverse.map{|e|('%04b'%e).tr('1','X').reverse}