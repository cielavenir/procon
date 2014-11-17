#!/usr/bin/ruby
require 'prime'
puts gets.to_i.prime_division.map(&:last).reduce(0,:+)>2 ? :YES : :NO