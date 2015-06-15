#!/usr/bin/ruby
loop{
	a,b=gets.split.map(&:to_i)
	break if a==0
	p (0..a/2).map{|i|(b-Math.hypot(i,a-i)).abs}.min
}