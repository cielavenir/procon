#!/usr/bin/ruby
require 'rational'
require 'prime'
p gets.to_i.times.map{gets.to_i}.reduce(:gcd).prime_division.reduce(1){|s,e|s*=e[1]+1}