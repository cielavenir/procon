#!/usr/bin/ruby
#5 prior trials are required.
p gets.split.map(&:to_i).reduce(:+)