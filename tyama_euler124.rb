#!/usr/bin/ruby
require 'prime'
p 1.step(100000).map{|n|[n.prime_division.reduce(1){|s,e|s*=e[0]},n]}.sort[9999][1]