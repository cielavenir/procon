#!/usr/bin/ruby
N=gets.to_i
a=gets.split.map(&:to_i)
puts N.times.map{|i|a[a[i]-1]}