#!/usr/bin/ruby
n,h=gets.split.map(&:to_i)
p n+gets.split.count{|e|e.to_i>h}