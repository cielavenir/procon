#!/usr/bin/env ruby
n,k=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).map.with_index(1).sort
s=0
b=a.take_while{|e|
	s+e[0]<=k && s+=e[0]
}
p b.size
puts b.map(&:last)*' '