#!/usr/bin/ruby
a=$<.map(&:to_i)
puts a.max+a.reduce(:+)>=300 ? :Yes : :No