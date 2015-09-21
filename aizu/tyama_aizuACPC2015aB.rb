#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
X=(N-1)/2
puts ([0]*X+[M]*(N-X))*' '