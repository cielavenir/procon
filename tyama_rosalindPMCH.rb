#!/usr/bin/ruby
s=ARGF.drop(1).map(&:chomp).join
p (1..s.scan('A').count).reduce(:*)*(1..s.scan('C').count).reduce(:*)