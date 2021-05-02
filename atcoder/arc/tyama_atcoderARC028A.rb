#!/usr/bin/ruby
n,a,b=gets.split.map(&:to_i)
puts (n-1)%(a+b)+1>a ? :Bug : :Ant