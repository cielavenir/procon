#!/usr/bin/ruby
while(a,b=gets.split.map(&:to_i))[0]!=0
	p (0..a/2).map{|i|(b-Math.hypot(i,a-i)).abs}.min
end