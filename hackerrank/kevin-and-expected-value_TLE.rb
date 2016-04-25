#!/usr/bin/ruby
y=lambda{|x|5.times.reduce(0){|s,_|Math.sqrt(x+s)}}
n=5000000
a=n.times.map(&y)
(1...n).each{|i|a[i]+=a[i-1]}
gets.to_i.times{
	m=gets.to_i
	p a[m-1]/m
}