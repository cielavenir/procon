#!/usr/bin/ruby
N,M=gets.split.map &:to_i
A,B=$<.map{|e|e.split.map(&:to_i).sort.reverse}
puts N<M||M.times.any?{|i|A[i]<B[i]}?:NO: :YES