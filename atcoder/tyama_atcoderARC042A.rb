#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
h=Hash.new(0)
1.step(M){|i|
	h[gets.to_i]=-i
}
puts [*1..N].sort_by{|i|[h[i],i]}