#!/usr/bin/ruby
n,k=gets.split.map &:to_i
p [[n,k-1].min-k/2,0].max
