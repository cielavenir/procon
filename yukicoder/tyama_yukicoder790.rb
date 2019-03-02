#!/usr/bin/ruby
def catalan(n) (n+2..2*n).reduce(1,:*)/(1..n).reduce(1,:*) end
p catalan gets.to_i
