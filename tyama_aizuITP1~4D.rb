#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
puts [a.min,a.max,a.reduce(:+)]*' '