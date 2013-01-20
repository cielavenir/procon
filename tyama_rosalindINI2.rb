#!/usr/bin/ruby
p gets.split.map{|e|e.to_i**2}.reduce(:+)