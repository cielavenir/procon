#!/usr/bin/ruby
p 1000-$<.map(&:to_i).reduce(:+)