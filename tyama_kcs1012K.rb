#!/usr/bin/ruby
p gets.split.map(&:to_i).reduce(:+)