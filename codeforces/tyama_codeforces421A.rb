#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i)
puts 1.step(n).map{|i|a.include?(i) ? 1 : 2}*' '