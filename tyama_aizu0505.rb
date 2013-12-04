#!/usr/bin/ruby
while(n=gets.to_i)>0
puts n.times.map{gets.split.map(&:to_i)}.transpose.map{|e|-e.reduce(:+)}.each.with_index(1).sort.map(&:last)*' 'end