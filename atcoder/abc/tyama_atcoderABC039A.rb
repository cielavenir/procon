#!/usr/bin/ruby
p gets.split.map(&:to_i).permutation(2).reduce(0){|s,(x,y)|s+x*y}