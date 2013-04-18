#!/usr/bin/ruby
require 'rational'
require 'prime'
a=gets.to_i.times.map{gets.to_i}
g=a.pop
a.each{|e|g=g.gcd e}
p g.prime_division.reduce(1){|s,e|s*=e[1]+1}