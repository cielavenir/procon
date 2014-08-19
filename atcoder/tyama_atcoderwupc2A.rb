#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
puts n*(n+1)*(2*n+1)/6%m