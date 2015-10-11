#!/usr/bin/ruby
N=gets.to_i
A=gets.split.map(&:to_i)
p A.reduce(:+)-[N,A.max].min