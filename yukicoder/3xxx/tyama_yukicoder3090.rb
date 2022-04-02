#!/usr/bin/ruby
n=gets.to_i
puts n.times.any?{gets.split.map(&:to_i)[1]==1} ? :Yes : :No
