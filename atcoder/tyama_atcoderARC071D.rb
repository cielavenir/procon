#!/usr/bin/ruby
n,m=gets.split.map &:to_i
a=gets.split.map(&:to_i).sort.map.with_index{|e,i|e*(2*i+1-n)}.reduce(:+)
b=gets.split.map(&:to_i).sort.map.with_index{|e,i|e*(2*i+1-m)}.reduce(:+)
p a*b%(10**9+7)
