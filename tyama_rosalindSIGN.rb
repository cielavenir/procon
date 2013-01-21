#!/usr/bin/ruby
n=gets.to_i
puts (1..n).reduce(:*)*(1<<n)
[*1..n].permutation{|e|
	(1<<n).times{|j|
		puts e.length.times.map{|i|((j>>i)&1)>0?-e[i]:e[i]}.join' '
	}
}