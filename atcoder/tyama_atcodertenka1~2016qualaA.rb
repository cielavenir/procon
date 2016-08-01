#!/usr/bin/ruby
p (1..100).select{|i|i%3>0&&i%5>0}.reduce(:+)