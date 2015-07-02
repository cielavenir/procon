#!/usr/bin/ruby
N=gets.to_i
D,*A=gets.split.map(&:to_i)
puts (1...N).all?{|i|i==(A[i-1]+[-D,D][i&1])%N} ? :Yes : :No