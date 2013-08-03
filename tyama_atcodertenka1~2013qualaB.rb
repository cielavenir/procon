#!/usr/bin/ruby
p gets.to_i.times.count{gets.split.map(&:to_i).reduce(:+)<20}