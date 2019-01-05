#!/usr/bin/ruby
n=gets.to_i
puts$<.map{|e|e.split.map &:to_i}.transpose.map{|e|e.reduce(:+)/n}*' '
