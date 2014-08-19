#!/usr/bin/ruby
n=gets.to_i
puts '.'*(n-2)+'+.'
puts '+'*n
(n-2).times{puts '.'*(n-2)+'+.'}