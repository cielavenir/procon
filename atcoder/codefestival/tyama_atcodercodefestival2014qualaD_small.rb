#!/usr/bin/ruby
a,k=gets.split.map(&:to_i)
raise if a>10**5
ret=10**5
(10**5*2).times{|i|
	next if i.to_s.chars.to_a.uniq.size>k
	ret=[ret,(a-i).abs].min
}
p ret