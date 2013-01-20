#!/usr/bin/ruby
n=gets.to_i
p (1..n).reduce(:*)
[*(1..n)].permutation{|e|puts e.join' '}