#!/usr/bin/ruby
s=$<.drop(1).map(&:chomp)*''
p (1..s.count('A')).reduce(:*)*(1..s.count('C')).reduce(:*)