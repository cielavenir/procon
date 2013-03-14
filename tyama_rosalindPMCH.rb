#!/usr/bin/ruby
s=$<.drop(1).map(&:chomp)*''
p (1..s.scan('A').count).reduce(:*)*(1..s.scan('C').count).reduce(:*)