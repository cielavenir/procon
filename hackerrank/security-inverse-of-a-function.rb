#!/usr/bin/ruby
N=gets.to_i
a=gets.split.map(&:to_i)
b=[nil]*N
N.times{|i|b[a[i]-1]=i+1}
puts b