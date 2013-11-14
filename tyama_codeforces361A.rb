#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
a=[1]*(n-1)+[k-n+1]
n.times{|i|puts a.rotate(i)*' '}