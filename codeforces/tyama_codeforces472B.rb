#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
p gets.split.map(&:to_i).sort.reverse.each_slice(k).reduce(0){|s,e|s+e[0]*2-2}