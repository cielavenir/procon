#!/usr/bin/ruby
N=gets.to_i
A=$<.map{|e|e.split.map(&:to_i)}
p N.times.reduce(0){|s,i|s+A[i][i]-A[i][N-1-i]}.abs