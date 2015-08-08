#!/usr/bin/ruby
N,K=gets.split.map &.to_i
puts [:Drew,:Lost,:Won][(N-K)%3]