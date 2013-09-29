#!/usr/bin/ruby
require 'prime'
puts gets.to_i.prime_division.map(&:first)[0,2]*' '