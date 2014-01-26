#!/usr/bin/ruby
n=gets.to_i
raise if n%2>0
p $<.map(&:to_i).sort.each_slice(2).reduce(0){|s,e|s+(e[0]-e[1]).abs}