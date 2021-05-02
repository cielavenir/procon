#!/usr/bin/ruby
p (1..gets.to_i).reduce{|s,e|s*e%(10**9+7)}
