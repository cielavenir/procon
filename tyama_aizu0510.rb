#!/usr/bin/ruby
p 2.times.map{gets.split.map(&:to_i).reduce(:+)}.max