#!/usr/bin/ruby
n,t=gets.split.map(&:to_i)
a=gets.chomp.split('+').reduce(0){|s,e|
	e=~/(\d+)$/
	s+=n**$1.to_i
}*t
puts a>10**9 ? :TLE : a