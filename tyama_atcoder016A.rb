#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
p [*1..n].reject{|e|e==m}.first