#!/usr/bin/ruby
gets
p gets.split.map(&:to_i).reduce(:+)*gets.split.map(&:to_i).reduce(:+)
