#!/usr/bin/ruby
p gets.split.map(&:to_i).combination(3).map{|x,y,z|x+y+z}.sort[-3]