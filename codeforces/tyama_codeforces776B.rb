#!/usr/bin/ruby
require 'prime'
n=gets.to_i
p n<3?1:2
puts (2..n+1).map{|e|e.prime? ? 1 : 2}*' '
