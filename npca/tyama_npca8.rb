#!/usr/bin/ruby
require 'prime'
p gets.to_i.step(gets.to_i).reduce(0){|s,i|s+i.prime_division.reduce(1){|s,e|s*(e[1]+1)}}