#!/usr/bin/ruby
p (1..gets.to_i).sum{|i|i**((i-1)%3+1)}
