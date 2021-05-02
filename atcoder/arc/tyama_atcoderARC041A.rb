#!/usr/bin/ruby
x,y=gets.split.map(&:to_i)
k=gets.to_i
p x+y-(k-y).abs