#!/usr/bin/ruby
n=gets.to_i
puts '*'*n
(n-2).times{|i|puts '*'+' '*(n-2)+'*'}
puts '*'*n