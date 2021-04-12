#!/usr/bin/ruby
S=Random.rand(1..20)
F=(1..S).reduce(1,:*)
N=Random.rand(0...F)
puts [N,S]*' '
