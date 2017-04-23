#!/usr/bin/ruby
a,b,n=gets.split.map(&:to_i)
r=Float::INFINITY
(1..n).each{|i|
	if b%i==0
		(1..n).each{|j|
			r=[r,(a-b/i*j).abs].min
		}
	end
}
p r
