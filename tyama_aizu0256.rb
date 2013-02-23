#!/usr/bin/ruby
p ARGF.map(&:to_i).reduce(:+)