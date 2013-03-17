#!/usr/bin/ruby
p gets.to_i.times.map{gets.split.map(&:to_i).sort}.transpose.map(&:max).reduce(:*)