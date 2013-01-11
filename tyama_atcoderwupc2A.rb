#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
puts (n+1).times.map{|e|e**2}.reduce(:+)%m