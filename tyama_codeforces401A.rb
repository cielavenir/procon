#!/usr/bin/ruby
n,x=gets.split.map(&:to_i)
s=gets.split.map(&:to_i).reduce(:+).abs
p (s+x-1)/x