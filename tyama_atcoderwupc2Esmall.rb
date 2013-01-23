#!/usr/bin/ruby
N,M,K=gets.split.map(&:to_i)
puts N-M<K ? M.times.map{gets.split[2].to_i}.sort[0,K-N+M].reduce(:+):0