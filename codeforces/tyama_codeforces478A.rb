#!/usr/bin/ruby
s=gets.split.map(&:to_i).reduce(:+)
p s==0||s%5>0 ? -1 : s/5