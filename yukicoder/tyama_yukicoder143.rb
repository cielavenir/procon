#!/usr/bin/ruby
k,n=gets.split.map(&:to_i)
p [-1,k*n-gets.split.map(&:to_i).reduce(:+)].max