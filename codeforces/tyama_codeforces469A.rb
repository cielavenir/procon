#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i)[1..-1]+gets.split.map(&:to_i)[1..-1]
puts (1..n).all?{|i|a.include?(i)} ? 'I become the guy.' : 'Oh, my keyboard!'