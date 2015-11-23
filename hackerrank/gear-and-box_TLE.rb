#!/usr/bin/ruby
n=gets.to_i/2
a=gets.split.map(&:to_i).sort.each_slice(n).to_a.transpose.map{|e|Rational(*e)}.reduce(:*)
puts '%d %d'%[a.denominator,a.numerator].map{|e|e%1000000007}