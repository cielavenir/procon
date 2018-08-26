#!/usr/bin/ruby
p (1..gets.to_i).reduce{|s,i|s*i*i*(2*i-1)%(10**9+7)}
