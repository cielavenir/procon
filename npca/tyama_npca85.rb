#!/usr/bin/ruby
require 'prime'
p gets.to_i.prime_division.map{|e|e[1]+1}.reduce(:*)