#!/usr/bin/ruby
p Range.new(*gets.split.map(&:to_i)).reduce(:+)