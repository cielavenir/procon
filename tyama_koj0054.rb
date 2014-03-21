#!/usr/bin/ruby
p 10-$<.map(&:to_i).reduce(:+)/200